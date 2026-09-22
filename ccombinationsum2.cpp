#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
public:
    void combination(vector<int> &nums, vector<int> &ans, vector<vector<int>> &res, int i, int target)
    {
        if (target == 0)
        {
            res.push_back(ans);
            return;
        }
        if (nums.size() <= i || target < 0)
        {
            return;
        }
        ans.push_back(nums[i]);
        combination(nums, ans, res, i + 1, target - nums[i]); // include
        ans.pop_back();
        int idx = i + 1;
        while (idx < nums.size() && nums[i] == nums[idx])
        {
            idx++;
        }
        combination(nums, ans, res, idx, target); // not include so target remains as it is
    }
    vector<vector<int>> combinationsum2(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        combination(nums, ans, res, 0, target);
        return res;
    }
};
int main()
{
    solution s;
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> final = s.combinationsum2(nums, target);
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