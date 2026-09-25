#include <iostream>
using namespace std;
class solution
{
public:
    bool isugly(int n)
    {
        if (n <= 0)
        {
            return false; // if this condition not mention then infinte loop
        }
        while (n % 2 == 0)
        {
            n = n / 2;
        }
        while (n % 3 == 0)
        {
            n = n / 3;
        }
        while (n % 5 == 0)
        {
            n = n / 5;
        }
        return n == 1;
        // Example 1: n = 12
        // 12 → divide by 2 → 6
        // 6  → divide by 2 → 3
        // 3  → divide by 3 → 1
    }
};
int main()
{
    solution s;
    cout << "is number is ugly:" << s.isugly(12);
    return 0;
}