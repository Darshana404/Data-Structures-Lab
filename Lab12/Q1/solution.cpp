// Code for Lab12 - Q1
// Program to implement graph using adjaceny matrix
#include<iostream>
using namespace std;
#define MAX 10

class graph
{
    private:
    int adjmatrix[MAX][MAX];
    int numvertices;
    public:
    graph(int vertices){
        if(vertices>MAX)
        {
            cout<<"Limit exceeded. Setting to "<<MAX<<endl;
            numvertices=MAX;
        }
        else{
            numvertices=vertices;
        }
        for(int i=0;i<numvertices;i++){
            for(int j=0;j<numvertices;j++){
                adjmatrix[i][j]=0;
            }
        }
    }
    bool isvalidvertex(int v)
    {
        return (v>=0 && v<numvertices);
    }
    void insertedge(int, int);
    void deleteedge(int,int);
    void searchedge(int,int);
    void displaygraph();
};

int main()
{
    int vertices;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    graph g(vertices);
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
                cout<<"Enter source vertex: ";
                cin>>src;
                cout<<"Enter destination vertex: ";
                cin>>dest;
                g.insertedge(src,dest);
                break;
            case 2:
                cout<<"Enter source vertex: ";
                cin>>src;
                cout<<"Enter destination vertex: ";
                cin>>dest;
                g.deleteedge(src,dest);
                break;
            case 3:
                cout<<"Enter source vertex: ";
                cin>>src;
                cout<<"Enter destination vertex: ";
                cin>>dest;
                g.searchedge(src,dest);
                break;
            case 4:
                g.displaygraph();
                break;
            case 5:
                return 0;
            default:
                cout<<"Enter a valid choice"<<endl;
        }
    }
}

//To insert an edge in the graph
void graph::insertedge(int src,int dest)
{
    if(isvalidvertex(src) && isvalidvertex(dest)){
        adjmatrix[src][dest]=1;
        adjmatrix[dest][src]=1;
        cout<<"Edge inserted"<<endl;
    }
    else{
        cout<<"Invalid vertex"<<endl;
    }
}

//To delete an edge from the graph
void graph::deleteedge(int src,int dest)
{
    if(isvalidvertex(src) && isvalidvertex(dest)){
        if(adjmatrix[src][dest]==1)
        {
            adjmatrix[src][dest]=0;
            adjmatrix[dest][src]=0;
            cout<<"Edge exists and is deleted"<<endl;
        }
        else{
            cout<<"Edge does not exist"<<endl;
        }
    }
    else{
        cout<<"Invalid vertex"<<endl;
    }
}

//To search for an edge in the graph
void graph::searchedge(int src,int dest)
{
    if(isvalidvertex(src) && isvalidvertex(dest)){
        if(adjmatrix[src][dest]==1){
            cout<<"Edge exists"<<endl;
        }
        else{
            cout<<"Edge does not exist"<<endl;
        }
    }
    else{
        cout<<"Invalid vertex"<<endl;
    }
}

//To display the graph
void graph::displaygraph()
{
    for(int i=0;i<numvertices;i++){
        for(int j=0;j<numvertices;j++){
            cout<<adjmatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}