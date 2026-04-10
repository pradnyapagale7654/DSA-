#include<iostream>
#include<vector>
#include<list>
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
bool dfs(int u,vector<bool>&vis,int par){
    vis[u]=true;
    for(auto it:l[u]){
        if(!vis[it]){ //not visited
            if(dfs(it,vis,u)){
                return true;
            }
        }
        //visited
        else if(it!=par){
            return true;
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
bool cycle=false;

for(int i=0;i<vertices;i++){
    if(!vis[i]){
        if(g.dfs(i,vis,-1)){
            cycle=true;
            break;
        }
    }
}

cout<<"cycle is present or not: "<<cycle;
}