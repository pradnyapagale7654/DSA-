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
void bfs(){

vector<bool>vis(v,false);
queue<int>q;

for(int i=0;i<v;i++){

    if(!vis[i]){

        q.push(i);
        vis[i]=true;

        while(!q.empty()){

            int u=q.front();
            q.pop();

            cout<<u<<" ";

            for(int x:l[u]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
    }
}

cout<<endl;
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
   cout<<"enter no of vertices:";
   cin>>vertices;
   cout<<"\n enter no of edges:";
   cin>>edges;
   int u,v;
  graph g(vertices);
  cout<<"Enter edges (u v):"<<endl;
  for(int i=0;i<edges;i++){
    cin>>u>>v;
    g.addedge(u,v);
}
    g.print();
    cout<<"bfs:";
    g.bfs();
    return 0;
}