#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class graph{
    public:
int v;
list<int>*l;
graph(int v){
    this->v=v;
    l=new list<int>[v];
}
void addedge(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);

}
void dfsh(int u,vector<bool>&vis){
cout<<u<<" ";
vis[u]=true;
for(int x:l[u]){
    if(!vis[x]){
        dfsh(x,vis);
    }
}
}

void print(){
    for(int i=0;i<v;i++){
        cout<<i<<":";
        for(int neighbor:l[i]){
            cout<<neighbor;
        }
        cout<<endl;
    }
}
};
int main(){
    int vertices,edges;
    int src=0;
   cout<<"enter no of vertices:";
   cin>>vertices;
   cout<<"\n enter no of edges:";
   cin>>edges;
   int u,v;
    vector<bool>vis(vertices,false);
  graph g(vertices);
  cout<<"Enter edges (u v):"<<endl;
  for(int i=0;i<edges;i++){
    cin>>u>>v;
    g.addedge(u,v);
}
    g.print();
    cout<<"dfs:";
    g.dfsh(src,vis);
    return 0;
}