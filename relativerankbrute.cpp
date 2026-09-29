#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class solution
{
public:
    vector<string> relativerank(vector<int> &score)
    {
        int n = score.size();
        vector<string> ans(n);
        vector<int> temp = score;
        sort(score.begin(), score.end(), greater<int>());
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans[i] = "gold medal";
            }
            else if (i == 1)
            {
                ans[i] = "silver medal";
            }
            else if (i == 2)
            {
                ans[i] = "bronze medal";
            }
            else
            {
                ans[i] = to_string(i + 1);
            }
        }
        // as we have to maintain the order
        vector<string> res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[i] == score[j])
                {
                    res[i] = ans[j];
                    break;
                }
            }
        }
        return res;
    }
};
int main()
{
    solution s;
    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> final = s.relativerank(score);
    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i] << " ";
    }
    cout << endl;
    return 0;
}