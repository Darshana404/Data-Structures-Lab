// Code for Lab4 - Q1
//list AdT using singly linked list
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
        };
        struct node *head;
    public:
        list()
        {head=NULL;}
        void insertbeg(int);
        void insertend(int);
        void insertpos(int,int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
        void display();
        void displayrev();
        void disrev(struct node *);
        void reverselink();
}l1;

int main()
{
    int choice,num,pos,val;
    while(1)
    {
        cout<<"1-Insert beginning\n2-Insert end\n3-Insert position\n4-Delete beginning\n5-Delete end\n6-Delete position\n7-Search\n8-Display\n9-Display reverse\n10-Reverse link\n11-Exit\n";
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
                }break;
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
                l1.displayrev();
                break;
            case 10:
                l1.reverselink();
                break;
            case 11:
                exit(0);
            default:
                cout<<"Enter a valid choice\n";
        }
    }
}

//To insert at the beginning
void list::insertbeg(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
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
        struct node *temp=head;
        newnode->data=num;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}

//To insert at a given position
void list::insertpos(int num,int pos)
{
    if(pos==0){
        l1.insertbeg(num);
    }
    else{
        struct node *temp=head;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        if(temp==NULL || pos==0)
        {
            l1.insertbeg(num);
            return;
        }
        for(int i=0;temp!=NULL && i<pos-1;i++)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"Position out of range\n";
            free(newnode);
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        // temp->next=newnode;
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
    if(temp->next==NULL)
    {
        val=temp->data;
        free(head);
        head=NULL;
        return(val);
    }
    else{
        val=temp->data;
        head=head->next;
        return(val);
    }
}

//To delete at the end
int list::delend()
{
    if(head==NULL){return 0;}
    int val;
    struct node *temp=head;
    if(temp->next==NULL)
    {
        l1.delbeg();
        return 0;
    }
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        val=temp->next->data;
        free(temp->next);
        temp->next=NULL;
        return val;
    }
}

//To delete at a position
int list::delpos(int pos)
{
    int val;
    if(pos==0){
        l1.delbeg();
        return 0;
    }
    else{
        struct node *temp=head;
        struct node *temp1=(struct node*)malloc(sizeof(struct node));
        for(int i=0;temp->next->next!=NULL && i<pos-1;i++){
            temp=temp->next;
        }
        temp1=temp->next;
        val=temp1->data;
        temp->next=temp->next->next;
        return val;
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
    struct node *temp=head;
    if(temp==NULL){return;}
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

//To display the list in reverse
void list::displayrev()
{
    struct node *temp=head;
    if(head==NULL){
        cout<<"The list is empty\n";
    }
    l1.disrev(temp);
    cout<<"\n";
}
void list::disrev(struct node *temp)
{
    if(temp==NULL){
        cout<<"NULL->";
        return;}
    disrev(temp->next);
    cout<<temp->data<<"->";
}

//To reverse the link
void list::reverselink()
{
    struct node *prev=NULL;
    struct node *temp=head;
    struct node *next=NULL;
    while(temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
}