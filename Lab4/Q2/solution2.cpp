//To perform some list operations
#include<iostream>
#include<stdlib.h>
#include "header.h"
using namespace std;

int main()
{
    int choice,num;
    while(1)
    {
        cout<<"1-Insert list1\n2-Insert list2\n3-Merge\n4-Display\n5-Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                int n,value;
                cout << "Enter the number of elements: ";
                cin >> n;
                for (int i=0; i<n; i++) {
                    cout << "Enter element " << i + 1 << ": ";
                    cin >> value;
                    lobj.insertasc(lobj.gethead1(),value);
                }
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
                break;
            case 3:
                lobj.mergelist();
                break;
            case 4:
                cout<<"List 1\n";
                lobj.display(lobj.gethead1());
                cout<<"List 2\n";
                lobj.display(lobj.gethead2());
                cout<<"Merged list\n";
                lobj.display(lobj.gethead3());
                break;
            case 5:
                exit(0);
            default:
                cout<<"Enter a valid choice\n";
        }
    }
}