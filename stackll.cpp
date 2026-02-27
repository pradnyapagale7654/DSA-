#include <iostream>
using namespace std;
class stack{
    public:
    int top;
    int stck[5];
    int size;
    stack(){
        top=-1;
        size=5;
    }
    void push(int val){
        if(top==size-1){
            cout<<"no addition possible";
        }
        else{
            top++;
            stck[top]=val;
            cout<<"elements which are pushed :"<<val<<"at pos:"<<top<<endl;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"cannot pop";
        }
        else{
            while(top!=-1){
            int data=stck[top];
            top--;
            cout<<"data which is deleted:"<<data<<endl;;
        }
        }
    }
    void peek(){
        if(top==-1){
            cout<<"underflow";
        }
        else{
            cout<<"peek element is:"<<stck[top];
        }
    }
};
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.peek();
    s.pop();
    return 0;
}