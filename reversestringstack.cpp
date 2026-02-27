#include<iostream>
#include<stack>
using namespace std;
class solution{
    public:
    void reversestring(string str){
        stack<char>s;
        for(int i=0;i<str.size();i++){
         s.push(str[i]);
        }
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
    }
};
int main(){
    solution s;
    s.reversestring("hello");
    return 0;
}