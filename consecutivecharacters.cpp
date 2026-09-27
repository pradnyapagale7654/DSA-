#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    int consecutivechar(string s)
    {
        int n = s.length();
        int power = 0;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            while (i < n && s[i] == s[i + 1])
            {
                count++;
                i++;
            }
            power = max(power, count);
        }
        return power + 1;
    }
};
int main()
{
    solution s;
    int ans = s.consecutivechar("abbcccddddeeeeedcba");
    cout << "consecutive characters length is:" << ans;
    return 0;
}