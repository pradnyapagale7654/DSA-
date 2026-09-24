#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    bool isugly(int num)
    {
        while (num % 2 == 0)
        {
            num = num / 2;
        }
        while (num % 3 == 0)
        {
            num = num / 3;
        }
        while (num % 5 == 0)
        {
            num = num / 5;
        }
        return num == 1; // leetcode says 1 is ugly number so if num==1 then we can say it is a ugly number
    }
    int uglynumber(int n)
    {
        vector<int> ugly;
        int num = 1;
        while (ugly.size() < n)
        {
            if (isugly(num))
            {
                ugly.push_back(num);
            }
            num++;
        }
        return ugly[n - 1];
    }
};
int main()
{
    solution s;
    int ans = s.uglynumber(9);
    cout << "ugly number is:" << ans;
    return 0;
}