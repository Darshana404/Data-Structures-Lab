// Code for Lab5 - Q1
// To implement list ADT using doubly linked list
#include<iostream>
#include<stdlib.h>
using namespace std;

//creating a class for the list

class list
{
    private:
        struct node{
            int data;
            struct node *next;
            struct node *prev;
        };
        struct node *head;
        struct node *tail;
    public:
        list()
        {head=NULL;tail=NULL;}
        void insertbeg(int);
        void insertend(int);
        void insertpos(int,int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
}l1;

int main()
{
    int choice,num,pos,val;
    while(1)
    {
        cout<<"1-Insert beginning\n2-Insert end\n3-Insert position\n4-Delete beginning\n5-Delete end\n6-Delete position\n7-Search\n8-Display\n9-Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<< "Enter the number to be inserted: ";
                cin>>num;
                l1.insertbeg(num);
                break;
            case 2:
                cout<< "Enter the number to be inserted: ";
                cin>>num;
                l1.insertend(num);
                break;
            case 3:
                cout<< "Enter the number to be inserted: ";
                cin>>num;
                cout<<"Enter the position: ";
                cin>>pos;
                l1.insertpos(num,pos);
                break;
            case 4:
                val=l1.delbeg();
                if(val==0){
                    cout<<"LIST IS EMPTY\n";
                }
                else{
                    cout<<"The deleted element is " << val <<"\n";
                }
                break;
            case 5:
                val=l1.delend();
                if(val==0){
                    cout<<"LIST IS EMPTY\n";
                }
                else{
                    cout<<"The deleted element is " << val <<"\n";
                }
                break;
            case 6:
                cout<<"Enter the position: ";
                cin>>pos;
                val=l1.delpos(pos);
                if(val==0){
                    cout<<"LIST IS EMPTY\n";
                }
                else{
                    cout<<"The deleted element is " << val <<"\n";
                }
                break;
            case 7:
                cout<<"Enter the element to be searched: ";
                cin>>num;
                pos=l1.search(num);
                if(pos==-1){
                    cout<<"The list is empty or the element does not exist\n";
                }
                else{
                    cout<<"The position of the element is "<<pos<<"\n";
                }
                break;
            case 8:
                l1.display();
                break;
            case 9:
                exit(0);
            default:
                cout<<"Enter a valid choice\n";
        }
    }
}

// To insert at the beginning
void list::insertbeg(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=tail=newnode;
    }
    else{
        head->prev=newnode;
        head=newnode;
    }
}

//To insert at the end
void list::insertend(int num)
{
    if(head==NULL)
    {
        l1.insertbeg(num);
    }
    else{
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}

//To insert at a position
void list::insertpos(int num,int pos)
{
    int val;
    int count=0;
    if(pos==1){
        l1.insertbeg(num);
    }
    else{
        struct node *temp=head;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        for (int i=1; temp && i<pos-1; i++) {
            temp=temp->next;
        }
        if(temp){
            newnode->data=num;
            newnode->next=temp->next;
            newnode->prev=temp;
            if(temp->next){temp->next->prev = newnode;}
            temp->next=newnode;
        }
        else{
            cout << "Position out of bounds" << endl;}
    }
}

//To delete at the beginning
int list::delbeg()
{
    if(head==NULL){
        return 0;
    }
    int val;
    struct node *temp=head;
    if(head==tail) //temp->next!=NULL
    {
        val=temp->data;
        tail=head=NULL;
        return(val);
    }
    else{
        val=temp->data;
        temp->next->prev=NULL;
        head=head->next;
        return(val);
    }
}

//To delete at the end
int list::delend()
{
    if(head==NULL){return 0;}
    int val;
    struct node *temp=tail;
    if(head==tail)
    {
        val=l1.delbeg();
        return val;
    }
    else{
        val=temp->data;
        temp->prev->next=NULL;
        tail=tail->prev;
        return val;
    }
}

//To delete at a position
int list::delpos(int pos)
{
    int val;
    int count=0;
    if(pos==1){
        val=l1.delbeg();
        return val;
    }
    else{
        struct node *temp=head;
        for (int i=1; temp && i<pos-1; i++) {
            temp=temp->next;
        }
        if(temp && temp->next) {
            struct node* temp1 = temp->next;
            val=temp1->data;
            temp->next=temp1->next;
            if (temp1->next){
                temp1->next->prev = temp;}
            delete temp1;
            return val;
        }
        else{
            cout<<"Position out of bounds" << endl;
        return -1;}
    }
}

//To search for a given element in the list
int list::search(int num)
{
    int count=0;
    struct node *temp=head;
    if(head==NULL){
        return -1;
    }
    while(temp!=NULL)
    {
        if(temp->data==num){
            return count;
        }
        temp=temp->next;
        count++;
    }
    return -1;
}

// To display the list
void list::display()
{
    if(head==NULL){
        cout<<"The list is empty\n";
        return;}
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data <<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
    temp=tail;
    cout<<"Displaying reverse:\n";
    cout<<"NULL";
    while(temp!=NULL)
    {
        cout<<"->"<<temp->data;
        temp=temp->prev;
    }
    cout<<"\n";
}