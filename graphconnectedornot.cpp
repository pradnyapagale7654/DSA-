#include<iostream>
#include<vector>
#include<queue>
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
        adj[u].push_back(v);
        adj[v].push_back(u);   // Undirected graph
    }

    bool isConnected()
    {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }

        // Check if all vertices visited
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
                return false;
        }

        return true;
    }
};

int main()
{
    int V, E;
    cout<<"Enter vertices: ";
    cin>>V;

    cout<<"Enter edges: ";
    cin>>E;

    Graph g(V);

    cout<<"Enter edges:\n";

    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    if(g.isConnected())
        cout<<"Graph is Connected";
    else
        cout<<"Graph is Not Connected";

    return 0;
}