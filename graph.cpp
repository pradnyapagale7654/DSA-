#include<iostream>
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
    return 0;
}