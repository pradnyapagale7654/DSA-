#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int findmaxconones(vector<int> &nums)
    {
        int n = nums.size();
        int maxcount = 0;
        int i = 0;
        while (i < n)
        {
            int count = 0;
            while (i < n && nums[i] == 1)
            {
                count++;
                i++;
            }
            maxcount = max(maxcount, count);
            i++;
        }
        return maxcount;
    }
};
int main()
{
    solution s;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int ans = s.findmaxconones(nums);
    cout << "maximum consecutive ones are:" << ans;
    return 0;
}