// Code for Lab3 - Q1
//Array implementations using list adt
#include<iostream>
#include<stdlib.h>
using namespace std;
//creating class for the array
class list
{
    private:
        int arr[5];
        int cur;
    public:
        list()
        {cur=-1;}
        void insertbeg(int);
        void insertend(int);
        void insertpos(int,int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
        void rotate(int);

}l1;
int main()
{
    int choice,pos,num,del;
    while(1)
    {
        cout << "\n1-Insert beginning\n2-Insert end\n3-Insert position\n4-Delete beginning\n5-Delete end\n6-Delete position\n7-Search\n8-Display\n9-Rotate\n10-Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                l1.insertbeg(num);
                break;
            case 2:
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                l1.insertend(num);
                break;
            case 3:
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                cout<<"Enter the position: ";
                cin>>pos;
                if(pos>=5 || pos<0){
                    cout<<"Invalid position, position should be between 0 and 5\n";
                }
                else{
                    l1.insertpos(num,pos);
                }
                break;
            case 4:
                del=l1.delbeg();
                if(del==0){
                    cout<<"Array empty, enter elements first\n";
                }
                else{
                    cout << "The deleted element is " << del << "\n";
                }
                break;
            case 5:
                del=l1.delend();
                if(del==0){
                    cout<<"Array empty, enter elements first\n";
                }
                else{
                    cout << "The deleted element is " << del << "\n";
                }
                break;
            case 6:
                cout<<"Enter the position: ";
                cin>>pos;
                if(pos>=5 || pos<0){
                    cout<<"Invalid position, position should be between 0 and 5\n";
                }
                else{
                    del=l1.delpos(pos);
                }
                if(del==0){
                    cout<<"Array empty, enter elements first\n";
                }
                else{
                    cout << "The deleted element is " << del << "\n";
                }
                break;
            case 7:
                cout<<"Enter the element to be searched: ";
                cin>>num;
                pos=l1.search(num);
                if(pos==0)
                {
                    cout<<"No such element found\n";
                }
                else{
                    cout << "The position of " << num << " is " << pos << "\n";
                }
                break;
            case 8:
                l1.display();
                break;
            case 9:
                cout<<"Enter the no. of rotations: ";
                cin>>num;
                l1.rotate(num);
                break;
            case 10:
                exit(0);
            default:
                cout <<"Invalid input,try again\n";
        }
    }
    return 0;
}

//To insert at the beginning
void list::insertbeg(int num)
{
    int temp;
    if(cur==-1)
    {
        arr[0]=num;
        cur+=1;
    }
    else if(cur<4){
        for(int i=cur;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0]=num;
        cur+=1;
    }   
    else{
        cout <<"Array full, cannot insert any more elements";
    } 
}

//To insert at the end
void list::insertend(int num)
{
    if(cur==-1){
        l1.insertbeg(num);
    }
    else if(cur<4){
        arr[cur+1]=num;
        cur+=1;
    }
    else{
        cout <<"Array full, cannot insert any more elements";
    }
}

//To insert at a position
void list::insertpos(int num,int pos)
{
    if(cur>=4)
    {
        cout <<"Array full, cannot insert any more elements";
    }
    else{
        if(pos==0){
            l1.insertbeg(num);
        }
        else if(pos==cur+1){
            l1.insertend(num);
        }
        else{
            for(int i=cur;i>=pos;i--){
                arr[i+1]=arr[i];
            }
            arr[pos]=num;
            cur+=1;
        }
    }
}

//To delete at the beginning
int list::delbeg()
{
    int temp;
    if(cur==-1){
        return 0;
    }
    else{
        temp=arr[0];
        for(int i=1;i<=cur;i++)
        {
            arr[i-1]=arr[i];
        }
        cur-=1;
        return temp;
    }
}

//To delete at the end
int list::delend()
{
    int temp;
    if(cur==-1){
        return 0;
    }
    else{
        temp=arr[cur];
        cur-=1;
        return temp;
    }
}

//To delete at a position
int list::delpos(int pos)
{
    int temp=0;
    if(cur==-1){
        return 0;
    }
    else if(pos>cur)
    {
        cout<<"No element found at the position\n";
        return -1;
    }
    else{
        temp=arr[pos];
        for(int i=pos+1;i<=cur;i++)
        {
            arr[i-1]=arr[i];
        }
        cur-=1;
        return temp;
    }
}

//To search for a given element
int list::search(int num){
    int random=0;
    if(cur==-1){
        cout << "Array empty\n";
    }
    else{
        for(int i=0;i<=cur;i++)
        {
            if(arr[i]==num){
                random=1;
                return i;
            }
        }
        if(random==0){
            return 0;
        }
    }
    return 1;   
}

//To rotate the array by n times
void list::rotate(int num){
    if(cur!=4){
        cout << "Array isn't full";
    }
    else{
        int temp;
        for(int j=0;j<num;j++){
            temp=arr[cur];
            for(int i=cur;i>=0;i--){
                arr[i]=arr[i-1];
            }
            arr[0]=temp;
        }
    }
}

//To display the elements of the list
void list::display(){
    if(cur==-1){
        cout << "Array empty\n";
    }
    else{
        for(int i=0;i<=cur;i++)
        {
            cout << arr[i] << "\n";
        }
    }
}