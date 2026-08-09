#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class solution{
    public:
int getnext(int n){
    int sum=0;
    while(n>0){
        int digits=n%10;
        sum+=digits*digits;
        n=n/10;
    }
    return sum;
}
bool ishappy(int n){
   int slow=n;
   int fast=getnext(n);
   while(slow!=fast && fast!=1){
    slow=getnext(slow);
    fast=getnext(getnext(fast));
   }
   return fast==1;
}
};
int main(){
    solution s;
    int n;
    cout<<"enter the number to check if it is happy or not: ";
    cin>>n;
    if(s.ishappy(n)){
        cout<<n<<" is a happy number";
    }
    else{
        cout<<n<<" is not a happy number";
    }
    return 0;
}