#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    bool iscycle(int src, int par, vector<vector<int>>& l, vector<int>& vis) {
        vis[src] = 1;

        for (auto it : l[src]) {

            if (!vis[it]) {
                if (iscycle(it, src, l, vis)) {
                    return true;
                }
            }
            else if (it != par) {
                return true;
            }
        }

        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        for (int i = n - 1; i >= 0; i--) {

            vector<vector<int>> l(n + 1);

            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                l[edges[j][0]].push_back(edges[j][1]);
                l[edges[j][1]].push_back(edges[j][0]);
            }

            vector<int> vis(n + 1, 0);

            bool cycle = false;

            for(int k = 1; k <= n; k++){
                if(!vis[k]){
                    if (iscycle(k, -1, l, vis)) {
                        cycle = true;
                        break;
                    }
                }
            }

            if(!cycle){
                return edges[i];
            }
        }

        return {};
    }
};


int main() {

    Solution obj;

    vector<vector<int>> edges = {
        {1,2},
        {1,3},
        {2,3}
    };

    vector<int> ans = obj.findRedundantConnection(edges);

    cout << "Redundant Edge: ";
    cout << ans[0] << " " << ans[1];

    return 0;
}