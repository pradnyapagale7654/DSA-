#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class solution{
    public:
  string removeoutermostparenthesis(string s){
    int count = 0;
        string ans = "";

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') {
                count++;

                if(count > 1) {
                    ans += s[i];
                }
            }
            else {
                count--;

                if(count > 0) {
                    ans += s[i];
                }
            }
        }

        return ans;
  }  
};
int main(){
    solution s;
    string res=s.removeoutermostparenthesis("(()())(())");
    cout<<"The string after removing outermost parenthesis is: "<<res<<endl;
    return 0;
}