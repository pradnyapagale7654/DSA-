#include <iostream>
using namespace std;
class solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
int main()
{
    solution s;

    cout << "Fibonacci series: ";

    for (int i = 0; i <= 4; i++)
    {
        cout << s.fib(i) << " ";
    }

    return 0;
}