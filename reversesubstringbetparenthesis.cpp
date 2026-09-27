#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class solution
{
public:
    string reverseparenthesis(string s)
    {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ')')
            {
                st.push(s[i]);
            }
            else
            {
                // ')'
                string ans = "";
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop(); // pop the '('
                // push ans again in stack
                for (char c : ans)
                {
                    st.push(c);
                }
            }
        }
        string res = "";
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
int main()
{
    solution s;
    string s1 = "(ed(et(oc))el)";
    string final = s.reverseparenthesis(s1);
    cout << "reverse of a substring between parenthesis:" << final;
    return 0;
}