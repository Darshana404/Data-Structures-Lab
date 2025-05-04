// Code for Lab8 - Q1
// Towers and blocks
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve() {
    int n;
    cout<<"Enter the no. of towers: ";
    cin>>n;
    vector<int> towers(n);

    for(int i=0; i<n; i++)
    {
        cout<<"Enter the no. of blocks in tower "<<i+1<<":";
        cin>>towers[i];
    }
    priority_queue<int> pq;
    
    for(int i=1; i<n; i++)
    {
        pq.push(towers[i]);
    }

    int tower1=towers[0];
    while (!pq.empty() && pq.top()>tower1) {
        int largest=pq.top();
        pq.pop();
        largest--;
        tower1++;
        pq.push(largest);
    }
    cout<<tower1<< endl;
}

int main() {
    solve();
    return 0;
}