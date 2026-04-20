#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class graph{
    public:
int v;
vector<pair<int,pair<int,int>>>edges;
graph(int v){
    this->v=v;
}
void addedge(int u,int v,int w){
    edges.push_back({w,{u,v}});
}
int findparent(int u,vector<int>&parent){
    if(parent[u]==u){
        return u;
    }
    return parent[u]=findparent(parent[u],parent);
}
void unionset(int u,int v,vector<int>&parent){
int pu=findparent(u,parent);
int pv=findparent(v,parent);
parent[pu]=pv;
}
int kruskal(){
    sort(edges.begin(),edges.end());
    vector<int>parent(v);
    int minval=0;
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    for(auto x:edges){
        int wt=x.first;
        int u=x.second.first;
        int v=x.second.second;
        int pu=findparent(u,parent);
        int pv=findparent(v,parent);
        if(pu!=pv){
            cout<<u<<"-"<<v<<":"<<wt;
            minval+=wt;
            unionset(u,v,parent);
        }
    }
    return minval;
}
};
int main(){
    int vertices;
    cout<<"enter no of vertices:";
    cin>>vertices;
    graph g(vertices);
    int choice,src,des,wt,s;
    do{
        cout<<"\n menu";
        cout<<"\n 1. add edge";
        cout<<"\n 2. kruskal :";
        cout<<"\n 3. exit";
        cout<<"enter choice:";
        cin>>choice;
       switch(choice){
           case 1:
           cout<<"enter src:";
           cin>>src;
           cout<<"enter des:";
           cin>>des;
           cout<<"enter wt:";
           cin>>wt;
           g.addedge(src,des,wt);
           break;
           case 2:
            cout<<"enter starting node:";
           cin>>s;
           cout<<"minimum cost:"<<g.kruskal();
           break;
           case 3:
           cout<<"Exiting";
           break;
           default:
           cout<<"invalid choice";
           
       }
    }while(choice!=3);
    return 0;
}