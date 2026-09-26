#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class solution
{
public:
    bool checkifexists(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(2 * nums[i]) != mp.end())
            {
                return true;
            }
            if (nums[i] % 2 == 0 && mp.find(nums[i] / 2) != mp.end())
            {
                return true; // if num%2 is exists and num/2 also there ex 6 is present 6%2==0 divisible by 2 then we check 3 is there if yes return true
            }
            // else insert in map
            mp[nums[i]] = 1; // insert 1 as we dont care about the value
        }
        return false;
    }
};
int main()
{
    solution s;
    vector<int> nums = {10, 2, 5, 3};
    cout << "exist or not:" << s.checkifexists(nums);
    return 0;
}