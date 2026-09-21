#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    void printsub(vector<int> &nums, vector<int> &ans, vector<vector<int>> &res, int i)
    {
        if (nums.size() == i)
        {
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);          // first value include so push in ans
        printsub(nums, ans, res, i + 1); // call for second value so i+1
        // backtracking
        ans.pop_back();
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[i])
        {
            idx++; // move idx until we skip duplicates completely
        }
        printsub(nums, ans, res, idx); // now call for exclude as it is unique
    }
    vector<vector<int>> subarray(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> ans;
        printsub(nums, ans, res, 0);
        return res;
    }
};
int main()
{
    solution s;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> finalans = s.subarray(nums);
    for (int i = 0; i < finalans.size(); i++)
    {
        for (int j = 0; j < finalans[i].size(); j++)
        {
            cout << finalans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}