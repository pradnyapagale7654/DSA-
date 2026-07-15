#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main() {
    Solution obj;

    string s = "anagram";
    string t = "gramana";

    if (obj.isAnagram(s, t)) {
        cout << "Strings are Anagrams";
    }
    else {
        cout << "Strings are Not Anagrams";
    }

    return 0;
}