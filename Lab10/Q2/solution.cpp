// Code for Lab10 - Q2
#include<iostream>
#include<vector>
#include<map>

using namespace std;
void calculate(int);
int main()
{
    int test,n;
    cout<<"Enter the no. of test cases: ";
    cin>>test;
    for(int i=0;i<test;i++)
    {
        cout<<"Enter the no. of words written by each person: ";
        cin>>n;
        calculate(n);
    }
}

void calculate(int n)
{
    vector<vector<string>>words(3,vector<string>(n));
    map<string,int>wordcount;
    vector<int>scores(3,0);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter 3 letter word in lowercase for person "<<i+1<<" : ";
            cin>>words[i][j];
            wordcount[words[i][j]]++;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(wordcount[words[i][j]]==1)
            {
                scores[i]+=3;
            }
            else if(wordcount[words[i][j]]==2)
            {
                scores[i]+=1;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        cout<<scores[i]<<" ";
    }
    cout<<endl;
}