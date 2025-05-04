// Code for Lab5 - Q3
#include<iostream>
#include<stdlib.h>
#include "osheader.h"

int fixed_time=100;
int main()
{
    int num,val,choice,rem;
    while(1)
    {
        cout<<"\n1-Insert process\n2-Execute\n3-Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the time: ";
                cin>>num;
                lobj.Insert(num);
                break;
            case 2:
                val=lobj.delbeg();
                rem=fixed_time-val;
                if(rem<0)
                {
                    cout<<"The execution is complete\n";
                }
                else{
                    lobj.Insert(rem);
                }
                lobj.display();
                break;
            case 3:
                exit(0);
            default:
                cout<<"Enter a valid choice\n";
        }
    }
}