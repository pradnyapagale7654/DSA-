#include<iostream>
using namespace std;

class graph{
public:
    int v;
    int adj[10][10];

    graph(int v){
        this->v = v;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                adj[i][j] = 0;
            }
        }
    }

    void addedge(int s,int d){
        adj[s][d] = 1;
        adj[d][s] = 1;   // undirected graph
    }

    void display(){
        cout<<"\nAdjacency Matrix:\n";
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
      void dfsrecu(int src,vector<bool>&vis){
        cout<<src<<" ";
        vis[src]=true;
        for(int i=0;i<v;i++){
            if(adj[src][i]==1 && !vis[i]){
                dfsrecu(src,vis);
            }
        }
    }
    void dfsnonrec(int src){
        vector<bool>vis(v,false);
        stack<int>st;
        st.push(src);
        vis[src]=true;
        while(!st.empty()){
            int t=st.top();
            st.pop();
            cout<<t<<" ";
            for(int i=v-1;i>=0;i--){  //to reverse the order 210 //give  012
                if(adj[t][i]==1 && !vis[i]){
                    vis[i]=true;
                    st.push(i);
                }
            }
        }
    }
};

int main(){
    int vertices, edges, choice;

    cout<<"Enter number of vertices: ";
    cin>>vertices;

    graph g(vertices);

    cout<<"Enter number of edges: ";
    cin>>edges;

    int src, dest;

    do{
        cout<<"\n--- MENU ---";
        cout<<"\n1. Add Edge";
        cout<<"\n2. Display Matrix";
        cout<<"\n3. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter source: ";
                cin>>src;
                cout<<"Enter destination: ";
                cin>>dest;
                g.addedge(src, dest);
                break;

            case 2:
                g.display();
                break;

            case 3:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}