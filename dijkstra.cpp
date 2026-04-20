#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<list>
#include<algorithm>
using namespace std;
class graph{
    public:
int v;
list<pair<int,int>>*l;
graph(int v){
    this ->v=v;
    l=new list<pair<int,int>>[v];
}
void addedge(int u,int v,int w){
    l[u].push_back({v,w});
    l[v].push_back({u,w});
}
void dijkstra(int src){
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   vector<int>dis(v,INT_MAX);
   dis[src]=0;
   pq.push({0,src});
   while(!pq.empty()){
    int dist=pq.top().first;
    int u=pq.top().second;
    pq.pop();
    if(dist>dis[u]) continue;
    for(auto x:l[u]){
        int v=x.first;
        int wt=x.second;
        if(dis[u]+wt<dis[v]){
            dis[v]=dis[u]+wt;
            pq.push({dis[v],v});
        }
    }
   }
   cout<<"vertex and distance:"<<endl;
   for(int i=0;i<v;i++){
    cout<<i<<":"<<dis[i];
   }
}
};
int main(){
    int vertices;
    cout<<"enter no of vertices:";
    cin>>vertices;
    graph g(vertices);
    int choice,u,v,wt,src;
    do{
        cout<<"\n   menu \n";
        cout<<"1. Add edge\n";
        cout<<"2.dijkstras\n";
        cout<<"3.exit\n";
        cout<<"enter choice:";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"entre src node:";
            cin>>u;
            cout<<"enter des node :";
            cin>>v;
            cout<<"enter weight:";
            cin>>wt;
            g.addedge(u,v,wt);
            break;
            case 2:
            cout<<"enter src vertex:";
            cin>>src;
            g.dijkstra(src);
            break;
            case 3:
            cout<<"exiting \n";
            break;
            default:
            cout<<"invalid choice\n";
        }
    }
    while(choice!=3);
    return 0;

}