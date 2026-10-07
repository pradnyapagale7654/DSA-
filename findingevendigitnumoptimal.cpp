#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> ans;

        int freq[10] = {0};

        // Count frequency of every digit
        for (int digit : digits)
        {
            freq[digit]++;
        }

        // Choose hundreds digit
        for (int i = 1; i <= 9; i++)
        {
            // First digit cannot be 0, so start from 1

            if (freq[i] == 0)
            {
                // If digit is not present
                continue;
            }

            freq[i]--;
            // Use this digit once, so decrease its count

            // Choose tens digit
            for (int j = 0; j <= 9; j++)
            {

                if (freq[j] == 0)
                {
                    continue;
                }

                freq[j]--;
                // Use this digit once

                // Choose units digit
                for (int k = 0; k <= 8; k += 2)
                {
                    // Third digit must be even:
                    // 0, 2, 4, 6, 8

                    if (freq[k] > 0)
                    {
                        int number = i * 100 + j * 10 + k;
                        ans.push_back(number);
                    }
                }

                freq[j]++;
                // Return the tens digit
            }

            freq[i]++;
            // Return the hundreds digit
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> digits = {2, 1, 3, 0};

    vector<int> ans = obj.findEvenNumbers(digits);

    cout << "3-digit even numbers are: ";

    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}