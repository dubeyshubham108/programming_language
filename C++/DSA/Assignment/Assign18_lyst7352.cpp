#include<iostream>
using namespace std;
struct node
{
    int item;
    int vertex;
    node *next;
};
class AdjList
{
    private:
        node *start;
        int vertex;
    public:
        AdjList();
        AdjList(int);
        void setVertex(int);
        void addNode(int,int);
        node* getStart();
        void printList();
        void removeFirstNode();
        ~AdjList();
};
AdjList::AdjList()
{
    start=nullptr;
}
void AdjList::setVertex(int v)
{
    vertex=v;
}
void AdjList::addNode(int v,int data)
{
    node* n=new node;
    n->item=data;
    n->vertex=v;
    n->next=start;
    start=n;
}
node* AdjList::getStart()
{
    return start;
}
void AdjList::printList()
{
    node *t;
    t=start;
    while(t)
    {
        cout<<" ("<<t->vertex<<","<<t->item<<")";
        t=t->next;
    }
}
AdjList::AdjList(int v)
{
    start=nullptr;
    vertex=v;
}
void AdjList::removeFirstNode()
{
    node *r;
    if(start)
    {
        r=start;
        start=start->next;
        delete r;
    }
}
AdjList::~AdjList()
{
    while(start)
        removeFirstNode();
}
class Graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        Graph();
        int getVCount();
        void createGraph(int);
        void printGraph();
        ~Graph();
};
Graph::Graph()
{
    v_count=0;
    arr=nullptr;
}
int Graph::getVCount()
{
    return v_count;
}
void Graph::createGraph(int vno)
{
    int v,data;
    v_count=vno;
    arr=new AdjList[v_count];
    for(int i=0;i<v_count;i++ )
    {
        cout<<"\nEnter vertex number: ";
        cin>>v;
        cout<<"\nEnter data to store: ";
        cin>>data;
        arr[i].addNode(v,data);
    }
}
void Graph::printGraph()
{
    for(int i=0;i<v_count;i++ )
    {
            cout<<endl;
            arr[i].printList();
    }
}
Graph::~Graph()
{
    delete []arr;
}
