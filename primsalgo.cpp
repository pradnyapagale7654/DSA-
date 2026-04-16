#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;
class graph{
    public:
int v;
list<pair<int,int>> *l;
graph(int v){
    this->v=v;
   l = new list<pair<int,int>>[v];
}
void addedge(int u,int v,int w){
    l[u].push_back({v,w});
    l[v].push_back({u,w});
}
int mstbyprims(){
    int minval=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  //min heap
    vector<bool>mst(v,false);
    pq.push({0,0});
    while(!pq.empty()){
   auto i = pq.top();
   int wt = i.first;
   int u = i.second;
         pq.pop();
       if(!mst[u]){
         mst[u]=true;
         minval+=wt;
         for(auto i:l[u]){
         int v=i.first;
         int w=i.second;

    if(!mst[v])
    pq.push({w,v});
            pq.push({w,v});
         }
       }
    }
    return minval;
}
};
int main(){
    int v,edges;
    int src,dest,wt;
    cout<<"enter no of vertices:";
    cin>>v;
    cout<<"\n enter no of edges:";
    cin>>edges;
     graph g(v);
    cout<<"\n enter src and des as(src,des) and weights:";
    for(int i=0;i<edges;i++){
    cin>>src>>dest>>wt;
     g.addedge(src,dest,wt);
    }
   cout<<"\nmst is:"<<g.mstbyprims();
}