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
}
bool iscycle(int src,vector<bool>&vis,vector<bool>&recurpath){
    vis[src]=true;
    recurpath[src]=true;
    for(auto it:l[src]){
        if(!vis[it]){
            if(iscycle(it,vis,recurpath)){
                return true;
            }
        }
        //visited 
        else if(recurpath[it]){  //visited and exists in recursive path
            return true;
        }
    }
    //backtrack
    //if cycle not found remove curr from recursive path  and backtrack
    recurpath[src]=false;
    return false;
}

    bool detectcycle(){
        vector<bool>vis(v,false);
        vector<bool>recurpath(v,false);

        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(iscycle(i,vis,recurpath)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
      int v,edges;
    int src,dest;
    cout<<"enter no of vertices:";
    cin>>v;
    cout<<"\n enter no of edges:";
    cin>>edges;
     graph g(v);
     vector<bool>vis(v,false);
     vector<bool>recurpath(v,false);
    cout<<"\n enter src and des as(src,des) ";
    for(int i=0;i<edges;i++){
    cin>>src>>dest;
     g.addedge(src,dest);
    }
   cout<<"\n cycle exist or not :"<<g.detectcycle();
}