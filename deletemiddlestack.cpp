#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void deleteelement(stack<int>&s){
    stack<int>temp;
    int len=s.size();
    int mid=len/2;
    for(int i=0;i<mid;i++){
       temp.push(s.top());
       s.pop();
    }
    s.pop();
    while(!temp.empty()){
       s.push(temp.top());
        temp.pop();
    }
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    deleteelement(s);
    cout<<"stack after deleting the middle element:";
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}