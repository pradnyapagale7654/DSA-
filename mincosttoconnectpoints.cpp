#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int v = points.size();
        vector<bool> mst(v,false);

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        pq.push({0,0});
        int cost = 0;

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int w = it.first;
            int u = it.second;

            if(mst[u]) continue;

            mst[u] = true;
            cost += w;

            for(int i=0;i<v;i++){

                if(!mst[i]){

                    int dist =
                    abs(points[u][0]-points[i][0]) +
                    abs(points[u][1]-points[i][1]);

                    pq.push({dist,i});
                }
            }
        }

        return cost;
    }
};

int main(){

    int n;
    cout<<"Enter number of points: ";
    cin>>n;

    vector<vector<int>> points(n, vector<int>(2));

    cout<<"Enter points (x y):"<<endl;

    for(int i=0;i<n;i++){
        cin>>points[i][0]>>points[i][1];
    }

    Solution obj;

    int result = obj.minCostConnectPoints(points);

    cout<<"Minimum Cost = "<<result<<endl;

    return 0;
}