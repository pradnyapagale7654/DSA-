// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#define size 5
class stack{
    public:
    int stck[size];
    int top;
   
    stack(){
        top=-1;
    }
  void push(int val){
      if(top==size-1){
          cout<<"stack is full cannot insert ";
      }
      else{
          top++;
          stck[top]=val;
          cout<<"val is:"<<val<<endl;
      }
  } 
  void pop(){
      if(top==-1){
          cout<<"stack is empty";
      }
      else{
          int data=stck[top];
          top--;
          cout<<"deleted element is:"<<data<<endl;
      }
  }
  void peek(){
      if(top==-1){
          cout<<"empty";
      }
      else{
          cout<<stck[top];
      }
  }
  void add(stack s2){
      int sum1=0;
      int sum2=0;
     for(int i=0;i<=top;i++){
         sum1=sum1+stck[i];
     }
     for(int i=0;i<=s2.top;i++){
         sum2=sum2+s2.stck[i];
     }
      cout<<"sum is:"<<sum1+sum2;
  }
};

int main(){
    stack s1,s2,s3;
    s1.push(10);
    s1.push(20);
    s2.push(30);
    s2.push(40);
   s1.add(s2);
  
    return 0;
}