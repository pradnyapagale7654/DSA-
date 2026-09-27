#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int longestcontinuousincresubseq(vector<int> &nums)
    {
        int n = nums.size();
        int maxcount = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            while (i + 1 < n && nums[i] < nums[i + 1])
            {
                count++;
                i++;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount + 1;
    }
};
int main()
{
    solution s;
    vector<int> nums = {1, 3, 5, 4, 7};
    int ans = s.longestcontinuousincresubseq(nums);
    cout << "longest continuous subsequence is:" << ans;
    return 0;
}