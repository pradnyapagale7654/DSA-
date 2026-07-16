#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    bool isanagram(string s,string t ){
        if(s.length()!=t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
vector<vector<string>>groupanagram(vector<string> &str){
vector<vector<string>>ans;
vector<bool>visited(str.size(),false);
for(int i=0;i<str.size();i++){
    if(visited[i]){
        continue;
    }
    vector<string>group;
    group.push_back(str[i]);
    visited[i]=true;
    for(int j=i+1;j<str.size();j++){
        if(!visited[j] && isanagram(str[i],str[j])){
            group.push_back(str[j]);
            visited[j]=true;
        }
    }
    ans.push_back(group);
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