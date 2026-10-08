#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int totalNumbers(vector<int> &digits)
    {

        int n = digits.size();
        int count = 0;

        int freq[10] = {0};

        // Store frequency of each digit
        for (int x : digits)
        {
            freq[x]++;
        }

        // i = last digit
        // Last digit must be even
        for (int i = 0; i <= 8; i += 2)
        {

            if (freq[i] == 0)
            {
                continue;
            }

            freq[i]--;

            // j = middle digit
            for (int j = 0; j <= 9; j++)
            {

                if (freq[j] == 0)
                {
                    continue;
                }

                freq[j]--;

                // k = first digit
                // First digit cannot be 0
                for (int k = 1; k <= 9; k++)
                {

                    if (freq[k] == 0)
                    {
                        continue;
                    }

                    int num = k * 100 + j * 10 + i;

                    count++;
                }

                // Restore j
                freq[j]++;
            }

            // Restore i
            freq[i]++;
        }

        return count;
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