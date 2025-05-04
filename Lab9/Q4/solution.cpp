// Code for Lab9 - Q4
#include<iostream>
#include<stack>
#include "treeadt.h"

int main()
{
    Tree tree;
    int choice;
    string str;
    while(1)
    {
        cout<<"\n1-Input postfix expression\n2-Construct Expression Tree\n3-Display preorder\n4-Display inorder\n5-Display postorder\n6-Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter a postfix expression: ";
                cin>>str;
                break;
            case 2:
                tree.insert(str);
                break;
            case 3:
                tree.disppreorder();
                cout<<endl;
                break;
            case 4:
                tree.dispinorder();
                cout<<endl;
                break;
            case 5:
                tree.disppostorder();
                cout<<endl;
                break;
            case 6:
                return 0;
            default:
                cout<<"Enter a valid choice"<<endl;
        }
    }
}