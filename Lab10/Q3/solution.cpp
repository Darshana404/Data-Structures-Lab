// Code for Lab10 - Q3
//To implement priority queue Adt using Max heap
#include<iostream>
#include<vector>
#include<deque>

using namespace std;
class maxheap
{
    vector<int>heap;
    public:
    void heapifyup(int);
    void heapifydown(int);
    void insert(int);
    int delheap();
    void display();
    bool search(int);
    void heapsort();
}h1;

int main()
{
    int choice,num,del;
    while(1){
        cout<<"1-Heapify Up\n2-Heapify Down\n3-Display\n4-Search\n5-Display sorted\n6-Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the number to be inserted: ";
                cin>>num;
                h1.insert(num);
                break;
            case 2:
                del=h1.delheap();
                if(del==-1){
                    cout<<"The heap is empty"<<endl;
                }
                else{
                    cout<<"The deleted element is: "<<del<<endl;
                }
                break;
            case 3:
                h1.display();
                break;
            case 4:
                cout<<"Enter the number to be searched: ";
                cin>>num;
                if(h1.search(num))
                {
                    cout<<"Element found"<<endl;
                }
                else
                    cout<<"No such element found"<<endl;
                break;
            case 5:
                h1.heapsort();
                break;
            case 6:
                return 0;
            default:
                cout<<"Enter a valid option"<<endl;
        }
    }
}

//To insert into the heap
void maxheap::heapifyup(int index)
{
    while(index>0){
        int parent=(index-1)/2;
        if(heap[index]>heap[parent]){
            swap(heap[index],heap[parent]);
            index=parent;
        }
        else{
            break;
        }
    }

}
void maxheap::insert(int value)
{
    heap.push_back(value);
    h1.heapifyup(heap.size()-1);
}

//To delete from the heap
void maxheap::heapifydown(int index)
{
    int size=heap.size();
    while(2*index+1<size){
        int left=2*index+1;
        int right=2*index+2;
        int largest=index;
        if(left<size && heap[left]>heap[largest])
            largest=left;
        if(right<size && heap[right]>heap[largest])
            largest=right;
        if(largest!=index)
        {
            swap(heap[index],heap[largest]);
            index=largest;
        }
        else
            break;
    }
}
int maxheap::delheap()
{
    if(heap.empty())
    {
        return -1;
    }
    int max=heap[0];
    heap[0]=heap.back();
    heap.pop_back();
    h1.heapifydown(0);
    return max;
}

//To search for an element
bool maxheap::search(int value)
{
    if(heap.empty()){return false;}
    for(int val:heap)
    {
        if(val==value)
        {
            return true;
        }
    }
    return false;
}

//To display in sorted order
void maxheap::heapsort()
{
    deque<int>sorted;
    while(!heap.empty())
    {
        sorted.push_front(h1.delheap());
    }
    for(int val:sorted)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}

//To display the heap
void maxheap::display()
{
    if(heap.empty()){cout<<"Heap is empty"<<endl;}
    else{
        for(int val:heap)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}