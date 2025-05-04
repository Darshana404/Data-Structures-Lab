#include<iostream>
#include<stdlib.h>
using namespace std;
class list{
    struct node{
        int data;
        struct node *next;
    }*head;
    public:
        list(){head=NULL;}
        void Insert(int);
        int delbeg();
        void display();
}lobj;

//To insert
void list::Insert(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(head==NULL){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        struct node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
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
    val=temp->data;
    if(temp->next==NULL)
    {
        free(head);
        head=NULL;
        return(val);
    }
    else{
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
        return(val);
    }
}

//To display all elements
void list::display()
{
    if (head == NULL) {
        cout << "Head is empty\n";
    } else {
        struct node *temp = head;
        cout << temp->data << " ";
        temp = temp->next;
        while (temp!=head){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}