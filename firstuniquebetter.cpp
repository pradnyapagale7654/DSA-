 #include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
 int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        // First pass: count frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Second pass: find first unique
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
    int main(){
        string str;
        cout<<"Enter the string: ";
        cin>>str;
        int result=firstUniqChar(str);
        if(result==-1){
            cout<<"No unique character found."<<endl;
        }
        else{
            cout<<"The index of the first unique character is: "<<result<<endl;
        }
        return 0;
    }