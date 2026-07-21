#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class solution{
    public:
int baseball(vector<string>&operations){
    stack<int>st;
    for(string op:operations){
        if(op=="D"){
            int first=st.top();
            st.push(2*first);
        }
        else if(op=="C"){
            st.pop();
        }
        else if(op=="+"){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.push(first);
            st.push(first+second);
        }
        else{
            //integer
            st.push(stoi(op));
        }
    }
    int sum=0;
    while(!st.empty()){
        sum+=st.top();
        st.pop();
    }
    return sum;
}
};
int main(){
    solution s;
    vector<string>operations={"5","2","C","D","+"};
    int ans=s.baseball(operations);
    cout<<"sum is:"<<ans;
    return 0;
}