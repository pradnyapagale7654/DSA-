#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class solution
{
public:
    int maxnestedparenthesis(string s)
    {
        stack<char> st;
        int maxcount = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
                count++;
            }
            maxcount = max(maxcount, count);
            if (s[i] == ')')
            {
                st.pop();
                count--;
            }
        }
        return maxcount;
    }
};
int main()
{
    solution s;
    string s1 = "(1+(2*3)+((8)/4))+1";
    int ans = s.maxnestedparenthesis(s1);
    cout << "maximum nested parenthesis :" << ans;
    return 0;
}