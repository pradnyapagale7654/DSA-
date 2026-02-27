#include<iostream>
#include<stack>
using namespace std;
void sortdescending(stack<int>&st){
    stack<int>temp;
    int current;
    while(!st.empty()){
         current=st.top();
        st.pop();
    
    while(!temp.empty() && temp.top()<current){
         st.push(temp.top());
         temp.pop();
    }

    temp.push(current);
}
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}
void print(stack<int>st){
    while(!st.empty()){
   cout<<st.top()<<endl;
   st.pop();
    }
}
int main(){
    stack<int>st;
    st.push(10);
    st.push(3);
    st.push(9);
    st.push(5);
    cout<<"before sorting:";
    print(st);
    sortdescending(st);
    cout<<"after sorting:";
    print(st);
    return 0;
}