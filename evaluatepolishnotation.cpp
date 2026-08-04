#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class solution{
    public:
int evaluatepolishnotation(vector<string>& tokens){
    stack<int>st;
    for(string c:tokens){
        if(c=="+"||c=="-"||c=="*"||c=="/"){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(c=="+") st.push(b+a);
            else if(c=="-") st.push(b-a);  // b is first and a is last element in stack
            else if(c=="*") st.push(b*a);
            else st.push(b/a);
        }
        else{
            st.push(stoi(c));
        }
    }
    return st.top();
}
};
int main(){
    solution s;
    vector<string>tokens={ "2", "1", "+", "3", "*" };
    cout<<s.evaluatepolishnotation(tokens);
    return 0;
}