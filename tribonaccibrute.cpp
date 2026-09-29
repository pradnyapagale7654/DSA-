#include <iostream>
using namespace std;
class solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        if (n == 2)
        {
            return 1;
        }
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};
int main()
{
    solution s;

    cout << "tribonacci series: ";

    for (int i = 0; i <= 4; i++)
    {
        cout << s.tribonacci(i) << " ";
    }

    return 0;
}