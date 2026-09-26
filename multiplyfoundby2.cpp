#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int num : nums)
        {
            mp[num] = 1; // store elements in map
        }
        for (int i = 0; i < n; i++)
        {
            if (mp.find(original) != mp.end())
            {
                original = 2 * original;
            }
        }
        return original;
    }
};
int main()
{
    solution s;
    vector<int> nums = {5, 3, 6, 1, 12};
    int ans = s.findFinalValue(nums, 3);
    cout << "original:" << ans;
    return 0;
}