#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    void perm(vector<int> &nums, vector<vector<int>> &res, vector<int> &ans, vector<int> &used)
    {
        if (ans.size() == nums.size())
        {
            res.push_back(ans);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == 1)
            {
                // already used skip
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
            {
                continue;
            }
            // else mark 1 and used
            used[i] = 1;
            ans.push_back(nums[i]); // choose
            perm(nums, res, ans, used);
            // backtrack
            ans.pop_back();
            used[i] = 0; // unmark
        }
    }
    vector<vector<int>> permutation(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> ans;
        vector<int> used(nums.size(), 0);
        perm(nums, res, ans, used);
        return res;
    }
};
int main()
{
    solution s;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> final = s.permutation(nums);
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