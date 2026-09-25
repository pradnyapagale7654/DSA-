#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    bool doubleexists(vector<int> &num1)
    {
        int n1 = num1.size();
        for (int i = 0; i < n1; i++)
        {
            for (int j = i + 1; j < n1; j++)
            {
                if (num1[i] == 2 * num1[j] || num1[j] == 2 * num1[i])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    solution s;
    vector<int> num1 = {10, 2, 5, 3};
    cout << "is double exists:" << s.doubleexists(num1);
    return 0;
}