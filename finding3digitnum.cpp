#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int totalNumbers(vector<int> &digits)
    {
        int n = digits.size();
        set<int> st;

        for (int i = 0; i < n; i++)
        {
            // i = last digit
            if (digits[i] % 2 != 0)
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                // don't use same index
                if (j == i)
                {
                    continue;
                }

                for (int k = 0; k < n; k++)
                {
                    // don't use same index
                    if (k == i || k == j)
                    {
                        continue;
                    }

                    // k = first digit, so it cannot be 0
                    if (digits[k] == 0)
                    {
                        continue;
                    }

                    int num = digits[k] * 100 +
                              digits[j] * 10 +
                              digits[i];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};

int main()
{
    Solution obj;

    vector<int> digits = {1, 2, 3, 4};

    int ans = obj.totalNumbers(digits);

    cout << "Total numbers: " << ans << endl;

    return 0;
}