#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n){
    if(n<=1){
        return false;
    }
    else{
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
               return false;
            }
        }
        return true;
    }
}
void printprime(int n){
    for(int i=1;i<n;i++){
        if(isprime(i)){
            cout<<i<<endl;
        }
    }
}
int main(){
int n;
cout<<"enter the value upto which prime numbers you want:";
cin>>n;
printprime(n);
return 0;
}