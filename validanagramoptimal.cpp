#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
bool isvalidanagram(string s,string t){
    if(s.length()!=t.length()){
        return false;
    }
    int freq[26]={0};
    for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}
};
int main() {
    solution obj;

    string s = "anagram";
    string t = "gramana";

    if (obj.isvalidanagram(s, t)) {
        cout << "Strings are Anagrams";
    }
    else {
        cout << "Strings are Not Anagrams";
    }

    return 0;
}