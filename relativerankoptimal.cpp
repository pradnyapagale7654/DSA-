#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution
{
public:
    vector<string> relativerank(vector<int> &score)
    {
        int n = score.size();

        vector<string> ans(n);

        priority_queue<pair<int, int>> pq;

        // Store score and original index
        for (int i = 0; i < n; i++)
        {
            pq.push({score[i], i});
        }

        int rank = 1;

        while (!pq.empty())
        {
            int scoreval = pq.top().first;
            int idx = pq.top().second;

            pq.pop();

            if (rank == 1)
            {
                ans[idx] = "Gold medal";
            }
            else if (rank == 2)
            {
                ans[idx] = "Silver medal";
            }
            else if (rank == 3)
            {
                ans[idx] = "Bronze medal";
            }
            else
            {
                ans[idx] = to_string(rank);
            }

            rank++;
        }

        return ans;
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