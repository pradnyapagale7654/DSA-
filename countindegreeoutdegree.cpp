#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    int V;
    vector<int>* adj;

public:

    Graph(int v)
    {
        V = v;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);   // Directed Graph
    }

    void degree()
    {
        vector<int> indegree(V,0);
        vector<int> outdegree(V,0);

        // Calculate outdegree and indegree
        for(int i=0;i<V;i++)
        {
            for(auto it : adj[i])
            {
                outdegree[i]++;
                indegree[it]++;
            }
        }

        cout<<"Vertex  Indegree  Outdegree\n";

        for(int i=0;i<V;i++)
        {
            cout<<i<<"        "
                <<indegree[i]<<"         "
                <<outdegree[i]<<endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.degree();

    return 0;
}