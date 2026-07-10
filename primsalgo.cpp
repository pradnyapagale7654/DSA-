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

        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        vector<bool> mst(v,false);

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
                }
            }
        }
        return minval;
    }
};

int main(){

    int vertices;
    cout<<"Enter no of vertices:";
    cin>>vertices;

    graph g(vertices);

    int choice,src,dest,wt;

    do{
        cout<<"\n----- MENU -----\n";
        cout<<"1. Add Edge\n";
        cout<<"2. Find MST using Prim's\n";
        cout<<"3. Exit\n";

        cout<<"Enter choice:";
        cin>>choice;

        switch(choice){

        case 1:
            cout<<"Enter Source:";
            cin>>src;

            cout<<"Enter Destination:";
            cin>>dest;

            cout<<"Enter Weight:";
            cin>>wt;

            g.addedge(src,dest,wt);
            break;

        case 2:
            cout<<"Minimum Spanning Tree Cost: ";
            cout<<g.mstbyprims()<<endl;
            break;

        case 3:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid Choice\n";
        }

    }while(choice!=3);

    return 0;
}