#include <iostream>
#include <vector>
using namespace std;
vector<int> pairsum(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};  
            }
        }
    }
    return {};  //if no pair returns empty
}

int main() {
    vector<int> nums = {2, 3, 4, 1, 5};
    int target = 5;
    vector<int> ans = pairsum(nums, target);// to store the pairs two sum pairs

    if (ans.size() == 2) {
        cout << "Pair indices: " << ans[0] << " " << ans[1] << endl;//you’re simply outputting the two indices that were stored in that returned vector.
    } else {
        cout << "No valid pair found\n";
    }
    return 0;
}