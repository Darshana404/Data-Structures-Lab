// Code for Lab9 - Q3
//To implement Tree Adt using binary search tree
#include<iostream>
#include<stdlib.h>
using namespace std;

class Bintree
{
    private:
        struct node{
            int data;
            node *left;
            node *right;
        }*root;
    public:
        Bintree()
        {
            root=NULL;
        }
        struct node* insert(node*,int);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
        struct node* search(node*,int);
        void insertnode(int num){
            root=insert(root,num);
        }
        void displaypreorder(){
            if(root)
                preorder(root);
            else
                cout<<"Tree is empty"<<endl;
        }
        void displayinorder(){
            if(root)
                inorder(root);
            else
                cout<<"Tree is empty"<<endl;
        }
        void displaypostorder(){
            if(root)
                postorder(root);
            else
                cout<<"Tree is empty"<<endl;
        }
        void searchnode(int num)
        {
            if(search(root,num))
                cout<<"Element found\n";
            else
                cout<<"Elemnt not found\n";
        }
}tree;

int main()
{
    int choice,num,elem;
    while(1)
    {
        cout<<"1-Insert\n2-Display preorder\n3-Display inorder\n4-Display postorder\n5-Search\n6-Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                int n;
                cout<<"Enter the no. of elemnts to be inserted: ";
                cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"Enter the number to be inserted: ";
                    cin>>num;
                    tree.insertnode(num);
                }
                break;
            case 2:
                tree.displaypreorder();
                break;
            case 3:
                tree.displayinorder();
                break;
            case 4:
                tree.displaypostorder();
                break;
            case 5:
                cout<<"Enter the number to be searched: ";
                cin>>num;
                tree.searchnode(num);
                break;
            case 6:
                return 0;
            default:
                cout<<"Enter a valid choice\n";
        }
    }
}

//To insert
Bintree::node* Bintree::insert(node *root, int num)
{
    if(root==NULL)
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        newnode->left=newnode->right=NULL;
        root=newnode;
        return newnode;
    }
    else{
        if(num<root->data){
            root->left=insert(root->left,num);
        }
        else{
            root->right=insert(root->right,num);
        }
    }
    return root;
}

//To display preorder
void Bintree::preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else{
        cout<<root->data<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

//To display inorder
void Bintree::inorder(node *root)
{
    if(root==NULL){
        return;
    }
    else{
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}

//To display postorder
void Bintree::postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<endl;
    }
}

//To search for an element
Bintree::node* Bintree::search(node *root,int num)
{
    if(root==NULL || root->data==num)
        return root;
    
    if(num<root->data){
        return search(root->left,num);
    }
    else{
        return search(root->right,num);
    }
}