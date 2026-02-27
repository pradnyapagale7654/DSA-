#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isvowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }

    string sortVowels(string s) {
        string vowels;
        
        // Collect vowels
        for(char c : s){
            if(isvowel(c)){
                vowels += c;
            }
        }

        // Sort vowels once
        sort(vowels.begin(), vowels.end());

        // Replace vowels in original positions
        int idx = 0;
        for(int i = 0; i < s.length(); i++){
            if(isvowel(s[i])){
                s[i] = vowels[idx++];
            }
        }

        return s;
    }
};

int main(){
    Solution sol;
    string result = sol.sortVowels("leetcode");
    cout << result;  // Output: leotcede
    return 0;
}
