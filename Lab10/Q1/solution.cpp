// Code for Lab10 - Q1
//Program to return the count of no. of elements removed until there're distinct elements in the array
#include<vector>
#include<iostream>
using namespace std;
void calculate(int);
bool exists(vector<int>,int);
int main()
{
    int t,n;
    cout<<"Enter the no. of test cases: ";
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Enter the no. of elemnts in the array: ";
        cin>>n;
        calculate(n);
    }
}

void calculate(int n)
{
    int count=0;
    vector<int>arr(n);
    vector<int>visited;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if(exists(visited,arr[i])){
            break;
        }
        visited.push_back(arr[i]);
        count++;
    }
    cout<<"No. of elements removed: "<<n-count<<endl;
}
bool exists(vector<int>arr,int num)
{
    for(int val:arr)
    {
        if(val==num){
            return true;
        }
    }
    return false;
}