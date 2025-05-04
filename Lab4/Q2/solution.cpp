// Code for Lab4 - Q2
#include<iostream>
#include<stdlib.h>
using namespace std;
class list
{
    struct node{
        int data;
        struct node *next;
    }*head1,*head2,*mergedhead;
    public:
        list(){head1=NULL,head2=NULL,mergedhead=NULL;}
        struct node*& gethead1(){
            return head1;
        }
        struct node*& gethead2(){
            return head2;
        }
        struct node*& gethead3(){
            return mergedhead;
        }
        // void sort();
        // void insert(int);
        void insertasc(struct node*& head,int);
        void mergelist();
        void display(struct node*);
}lobj;

int main()
{
    int choice,num;
    while(1)
    {
        cout<<"1-Insert in ascending\n2-Merge\n3-Display\n4-Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                lobj.insertasc(lobj.gethead1(),num);
                break;
            case 2:
                int n,value;
                cout << "Enter the number of elements: ";
                cin >> n;
                for (int i=0; i<n; i++) {
                    cout << "Enter element " << i + 1 << ": ";
                    cin >> value;
                    lobj.insertasc(lobj.gethead2(),value);
                }
                lobj.mergelist();
                cout<<"Merged list\n";
                lobj.display(lobj.gethead3());
                break;
            case 3:
                cout<<"List 1\n";
                lobj.display(lobj.gethead1());
                cout<<"List 2\n";
                lobj.display(lobj.gethead2());
                break;
            case 4:
                exit(0);
            default:
                cout<<"Enter a valid choice\n";
        }
    }
}

//To insert in ascending
void list::insertasc(struct node*& head,int num)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }
    else{
        struct node *temp=head;
        if (num<head->data) {
            newnode->next=head;
            head=newnode;
            return;
        }
        while(temp->next!=NULL && temp->next->data < num)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

//To merge two sorted lists
void list::mergelist()
{
    struct node* temp1=head1;
    struct node* temp2=head2;
    if(temp1==NULL){return;}
    if(temp2==NULL){return;}
    if (temp1->data <= temp2->data) {
        mergedhead = head1;
        temp1 = temp1->next;
    } else {
        mergedhead =temp2;
        temp2=temp2->next;
    }
    struct node* temp3=mergedhead;
    while (temp1!=NULL && temp2 !=NULL) {
        if (temp1->data<=temp2->data) {
            temp3->next=temp1;
            temp1=temp1->next;
        } else {
            temp3->next =temp2;
            temp2 =temp2->next;
        }
        temp3=temp3->next;
    }
    if (temp1!= nullptr) {
        temp3->next =temp1;
    }else{
        temp3->next=temp2;
    }
}

// To display the list
void list::display(struct node *head)
{
    struct node *temp=head;
    if(temp==NULL){return;}
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}