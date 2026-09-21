#include <iostream>
#include <vector> // same as subsets
using namespace std;
class solution
{
public:
    void comb(int &n, int &k, vector<int> &ans, vector<vector<int>> &res, int i)
    {
        if (k == ans.size())
        {
            res.push_back(ans);
            return;
        }
        // check i is in range of 1 to n
        if (i > n)
        {
            return;
        }
        ans.push_back(i);
        comb(n, k, ans, res, i + 1);
        // backtrack
        ans.pop_back();
        comb(n, k, ans, res, i + 1);
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> ans;
        comb(n, k, ans, res, 1);
        return res;
    }
};
int main()
{
    solution s;
    int n = 4;
    int k = 2;
    vector<vector<int>> final = s.combine(n, k);
    for (int i = 0; i < final.size(); i++)
    {
        for (int j = 0; j < final[i].size(); j++)
        {
            cout << final[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}