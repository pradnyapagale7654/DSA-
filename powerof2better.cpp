#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n % 2 == 0)
        {
            n = n / 2;
        }
        return n == 1;
    }
};
int main()
{
    Solution s;
    int n = 16;
    bool res = s.isPowerOfTwo(n);
    if (res)
    {
        cout << n << " is a power of two." << endl;
    }
    else
    {
        cout << n << " is not a power of two." << endl;
    }
    return 0;
}