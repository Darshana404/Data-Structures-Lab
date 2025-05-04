// Code for Lab9 - Q1
//A program to remove ith position from a sequence of n integers
#include<iostream>
#include<vector>
using namespace std;

void solve();
int min_elem(vector<int>);
int main()
{
    int test;
    cout<<"Enter the no. of test cases: ";
    cin>>test;
    for(int i=0;i<test;i++)
    {
        solve();
    }
}

int min_elem(vector<int>arr)
{
    int smallest=arr[0];;
    for(int num:arr)
    {
        if(num<smallest)
        {
            smallest=num;
        }
    }
    return smallest;
}
void solve()
{
    int seq,n;
    cout<<"Enter the length of sequence: ";
    cin>>seq;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int>sequence(seq);
    vector<int>arr(n);
    cout<<"Enter the sequence: ";
    for(int i=0;i<seq;i++)
    {
        cin>>sequence[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the no. of players in round"<<i+1<<": ";
        cin>>arr[i];
    }
    int smallest=min_elem(sequence);
    for(int num:arr){
        if(num<smallest)
        {
            cout<<num<<" ";
        }
        else{
            cout<<smallest-1<<" ";
        }
    }
    cout<<endl;
}
