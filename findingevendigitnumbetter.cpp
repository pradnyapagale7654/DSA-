#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class solution
{
public:
    vector<int> findingeven(vector<int> &digits)
    {
        set<int> st;
        int n = digits.size();
        for (int i = 0; i < n; i++)
        { // coose 3rd digit
            if (digits[i] % 2 != 0)
            {
                // odd number so skip
                continue;
            }
            for (int j = 0; j < n; j++)
            { // take 2nd digit
                if (i == j)
                {
                    continue; // skip if same index
                }
                for (int k = 0; k < n; k++)
                { // take 1st digit
                    if (k == i || k == j)
                    {
                        continue; // skip if same index
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k]; // form the number
                    st.insert(num);                                         // add to set
                }
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
int main()
{
    solution obj;
    vector<int> digits = {1, 2, 3, 4};
    vector<int> ans = obj.findingeven(digits);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}