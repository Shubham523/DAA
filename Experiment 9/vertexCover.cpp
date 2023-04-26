#include<iostream>
#include <list>
using namespace std;
 

class Graph
{
    int V;    
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void printVertexCover();  
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 

void Graph::printVertexCover()
{

    bool visited[V];
    for (int i=0; i<V; i++)
        visited[i] = false;
 
    list<int>::iterator i;
 
    for (int u=0; u<V; u++)
    {
     
        if (visited[u] == false)
        {
     
            for (i= adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
   
                     visited[v] = true;
                     visited[u]  = true;
                     
                     cout<<"\nConsidering age "<<u<<" and "<<v<<endl;
                     break;
                }
            }
        }
    }
 
cout<<"\nThe Vertex Cover is as follows : ";
    for (int i=0; i<V; i++)
    
    {
        
        if (visited[i]) {
          
          cout << i << " ";
        }
        
    }     
}
 

int main()
{
    int v;
    cout<<"\nEnter the number of vertices : ";
    cin>>v;
   
    Graph g(v);
   
    int e;
    cout<<"\nEnter the number of edges : ";
    cin>>e;
    cout<<endl;
   
    for(int i=0;i<e;i++){
    int a,b;
      cout<<"Enter the vertices for the  edge "<<i+1<<" :";
      cin>>a>>b;
      g.addEdge(a,b);
    }
 
    
    g.printVertexCover();
    
    cout<<endl<<endl;
 
    return 0;
}
