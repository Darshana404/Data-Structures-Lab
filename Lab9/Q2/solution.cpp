// Code for Lab9 - Q2
//To compare the strengths of diffeent players
#include<iostream>
#include<vector>
using namespace std;

void strengths();

int main()
{
    int test;
    cout<<"Enter the no. of test cases: ";
    cin>>test;
    for(int i=0;i<test;i++)
    {
        strengths();
    }
}

void strengths()
{
    int n;
    cout<<"Enter the length of the array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the strengths of player "<<i+1<<": ";
        cin>>arr[i];
    }
    int largest=arr[0];
    int second=arr[0];
    for(int num:arr)
    {
        if(num>largest)
        {
            second=largest;
            largest=num;
        }
        else if(num>second && num<largest)
        {
            second=num;
        }
    }
    for(int num:arr){
        if(num==largest)
        {
            cout<<largest-second<<" ";
        }
        else{
            cout<<num-largest<<" ";
        }
    }
    cout<<endl;
}