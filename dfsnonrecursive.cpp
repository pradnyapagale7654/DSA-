#include<iostream>
#include<list>
#include<vector>
#include<stack>
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

void dfs(){

vector<bool>vis(v,false);
stack<int>st;

st.push(0);     // start node
vis[0]=true;

while(!st.empty()){

    int u=st.top();
    st.pop();

    cout<<u<<" ";

    for(int x:l[u]){
        if(!vis[x]){
            vis[x]=true;
            st.push(x);
        }
    }
}

}

};

int main(){

graph g(5);

g.addedge(0,1);
g.addedge(0,2);
g.addedge(1,3);
g.addedge(2,4);

g.dfs();

}