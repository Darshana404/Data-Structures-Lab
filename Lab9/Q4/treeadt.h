#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

class Tree{
    private:
        struct node{
            char data;
            node *left;
            node *right;
        }*root;
    public:
        Tree()
        {root=NULL;}
        node* construct(const string&);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
        void insert(string ch)
        {
            root=construct(ch);
        }
        void disppreorder() { preorder(root); }
        void dispinorder() { inorder(root); }
        void disppostorder() { postorder(root); }
};

bool isoperator(char ch)
{
    return(ch=='+'||ch=='-'||ch=='*'||ch=='/');
}

Tree::node* Tree::construct(const string& postfix)
{
    stack<Tree::node*>stk;
    for(char ch:postfix)
    {
        node* newnode=new node();
        newnode->data=ch;
        newnode->left=newnode->right=NULL;

        if(isoperator(ch))
        {
            newnode->right=stk.top();
            stk.pop();
            newnode->left=stk.top();
            stk.pop();
        }
        stk.push(newnode);
    }
    return stk.top();
}

//To display preorder
void Tree::preorder(node *root)
{
    if(!root){return;}
    else{
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

//To display inorder
void Tree::inorder(node* root) {
    if(!root){
        return;
    }
    else{
        if(isoperator(root->data))
        {
            cout<<"(";
        }
        inorder(root->left);
        cout<<root->data << " ";
        inorder(root->right);
        if(isoperator(root->data))
        {
            cout<<")";
        }
    }
}

//To display postorder
void Tree::postorder(node* root) {
    if(!root){return;}
    else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}