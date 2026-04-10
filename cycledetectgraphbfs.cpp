#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
bool iscyclebfs(int src,vector<bool>&vis){
    queue<pair<int,int>>q;
    q.push({src,-1});
    vis[src]=true;
    while(!q.empty()){
        int u=q.front().first;
        int paru=q.front().second;
        q.pop();
        for(int v:l[u]){
            if(!vis[v]){
                q.push({v,u});
                vis[v]=true;
            }
            else if(v!=paru){
                return true;
            }
        }
    }
    return false;
}
bool iscycle(){
    vector<bool>vis(v,false);
    for(int i=0;i<v;i++){
       if(!vis[i]){
        if(iscyclebfs(i,vis)){
            return true;
        }
       }
    }
    return false;
}
};
int main(){
   int vertices,edges;
   int par=-1;
   cout<<"enter no of vertices:";
   cin>>vertices;
   cout<<"\n enter no of edges:";
   cin>>edges;
   int u,v;
   vector<bool>vis(vertices,false);
  graph g(vertices);
  cout<<"Enter edges from 0 to vertices(u v):"<<endl;
  for(int i=0;i<edges;i++){
    cin>>u>>v;
    g.addedge(u,v);
}
cout<<"is cycle is presnet:"<<g.iscycle();
}