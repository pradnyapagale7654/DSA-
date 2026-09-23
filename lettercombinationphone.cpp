#include <iostream>
#include <vector>
#include <map>
using namespace std;
class solution
{
public:
    void letter(string &digits, vector<string> &res, string &ans, int i, map<char, string> &mp)
    {
        if (i == digits.size())
        {
            res.push_back(ans);
            return;
        }
        string letters = mp[digits[i]];
        for (char c : letters)
        {
            ans.push_back(c);
            letter(digits, res, ans, i + 1, mp);
            ans.pop_back();
        }
    }
    vector<string> lettercombination(string digits)
    {
        vector<string> res;
        map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string ans = "";
        letter(digits, res, ans, 0, mp);
        return res;
    }
};
int main()
{
    solution s;
    string digits = "23";
    vector<string> final = s.lettercombination(digits);
    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i] << " " << endl;
    }
    return 0;
}