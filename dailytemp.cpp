#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> st;
        vector<int> result(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; i--) {

            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            if (!st.empty()) {
                result[i] = st.top() - i;
            }

            st.push(i);
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> result = s.dailyTemperatures(temperatures);

    for (int days : result) {
        cout << days << " ";
    }

    return 0;
}