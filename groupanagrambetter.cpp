#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class solution{
    public:
vector<vector<string>>groupanagram(vector<string> &str){
vector<vector<string>>ans;
unordered_map<string,vector<string>>mp;
for(auto st:str){
    string key=st;
    sort(key.begin(),key.end());
    mp[key].push_back(st);
}
for(auto it:mp){
    ans.push_back(it.second);
}
return ans;
}
};
int main() {

    solution s;

    vector<string> str = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    vector<vector<string>> ans = s.groupanagram(str);

    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}