// Code for Lab11 - Q1
//program to implement hash ADT using linear probing
#include<iostream>
using namespace std;
#define size 10

class hashtable
{
    private:
        int table[size];
        bool isoccupied[size];
    public:
        hashtable()
        {
            for(int i=0;i<size;i++)
            {
                table[i]=-1;
                isoccupied[i]=false;
            }
        }
        int hashfunction(int key){
            return key%size;
        }
        void insert(int);
        void remove(int);
        void search(int);
        void display();
}ht1;

int main()
{
    int choice,key;
    while(1)
    {
        cout<<"1-Insert\n2-Delete\n3-Search\n4-Display\n5-Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>key;
                ht1.insert(key);
                break;
            case 2:
                cout<<"Enter the element to be deleted: ";
                cin>>key;
                ht1.remove(key);
                break;
            case 3:
                cout<<"Enter the element to be searched: ";
                cin>>key;
                ht1.search(key);
                break;
            case 4:
                ht1.display();
                break;
            case 5:
                return(0);
            default:
                cout<<"Enter a valid choice"<<endl;
        }
    }
}

//To insert into the table
void hashtable::insert(int key)
{
    int index=ht1.hashfunction(key);
    int i=0;
    while(isoccupied[(index+i)%size])
    {
        i++;
        if(i==size){
            cout<<"Table is full"<<endl;
            return;
        }
    }
    int finalindex=(index+i)%size;
    table[finalindex]=key;
    isoccupied[finalindex]=true;
}

//To delete an element
void hashtable::remove(int key)
{
    int index=ht1.hashfunction(key);
    int i=0;
    while(isoccupied[(index+i)%size]){
        int cur=(index+i)%size;
        if(table[cur]==key)
        {
            isoccupied[cur]=false;
            table[cur]=-1;
            cout<<"Deleted "<<key<<" from index "<<cur<<endl;
            return;
        }
        i++;
        if(i==size)
            break;
    }
    cout<<"Element not found"<<endl;
}

//To search for an element
void hashtable::search(int key)
{
    int index=hashfunction(key);
    int i=0;
    while(isoccupied[(index+i)%size])
    {
        int cur=(index+i)%size;
        if(table[cur]==key)
        {
            cout<<"Found "<<key<<" at index "<<cur<<endl;
            return;
        }
        i++;
        if(i==size)
            break;
    }
    cout<<"Element not found"<<endl;
}

//To display the table
void hashtable::display()
{
    cout<<"Displayng hashtable: \n";
    for(int i=0; i<size;i++)
    {
        if(isoccupied[i])
            cout<<i<<" -> "<<table[i]<<endl;
        else
            cout<<i<<" -> EMPTY"<<endl;
    }
}