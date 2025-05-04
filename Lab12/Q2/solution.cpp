// Code for Lab12 - Q2
// Program to implement graph using adjacency list
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph
{
    private:
        int numvertices;
        vector<list<int>>adjlist;
    public:
    Graph(int vertices)
    {
        numvertices=vertices;
        adjlist.resize(vertices);
    }
    void insertedge(int,int);
    void deleteedge(int,int);
    void searchedge(int,int);
    void displaygraph();
    bool isvalidvertex(int v)
    {
        return (v>=0 && v<numvertices);
    }
};

int main()
{
    int vertices;
    cout<<"Enter the number of vertices in the graph: ";
    cin>>vertices;
    Graph g(vertices);
    int choice,src,dest;
    while(1)
    {
        cout<<"\nGraph Operations Menu:\n";
        cout<<"1.Insert edge\n2.Delete edge\n3.Search edge\n4.Display graph\n5.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the source vertex: ";
                cin>>src;
                cout<<"Enter the destination vertex: ";
                cin>>dest;
                g.insertedge(src,dest);
                break;
            case 2:
                cout<<"Enter the source vertex: ";
                cin>>src;
                cout<<"Enter the destination vertex: ";
                cin>>dest;
                g.deleteedge(src,dest);
                break;
            case 3:
                cout<<"Enter the source vertex: ";
                cin>>src;
                cout<<"Enter the destination vertex: ";
                cin>>dest;
                g.searchedge(src,dest);
                break;
            case 4:
                g.displaygraph();
                break;
            case 5:
                return(0);
        }
    }
}

//To insert an edge in the graph
void Graph::insertedge(int src,int dest)
{
    if(isvalidvertex(src) && isvalidvertex(dest))
    {
        adjlist[src].push_back(dest);
        adjlist[dest].push_back(src);
        cout<<"Edge inserted"<<endl;
    }
    else{
        cout<<"Invalid vertex"<<endl;
    }
}

//To delete an edge in the graph
void Graph::deleteedge(int src,int dest)
{
    if(isvalidvertex(src) && isvalidvertex(dest))
    {
        for(int vertex: adjlist[src]){
            if(vertex==dest){
                adjlist[src].remove(dest);
                adjlist[dest].remove(src);
                cout<<"Edge deleted"<<endl;
                return;
            }
        }
        cout<<"Edge not found"<<endl;
    }
    else{
        cout<<"Invalid vertex"<<endl;
    }
}

//To search for an edge in the graph
void Graph::searchedge(int src,int dest)
{
    if(isvalidvertex(src) && isvalidvertex(dest)){
        for(int vertex: adjlist[src]){
            if(vertex==dest){
                cout<<"Edge found"<<endl;
                return;
            }
        }
        cout<<"Edge not found"<<endl;
    }
    else{
        cout<<"Invalid vertex"<<endl;
    }
}

//To display the graph
void Graph::displaygraph()
{
    for(int i=0;i<numvertices;i++){
        cout<<i<<"->";
        for(int vertex:adjlist[i])
        {
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
}