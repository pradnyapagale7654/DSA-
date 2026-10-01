#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> sortedarr(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[i] * nums[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> ans = obj.sortedarr(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}