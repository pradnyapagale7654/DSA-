#include<iostream>
using namespace std;
bool isarmstrong(int n){
    int original=n;
    int sumofcubes=0;
    int digit;
    while(n!=0){
        digit=n%10;
        sumofcubes=sumofcubes+(digit*digit*digit);
        n=n/10;
    }
    return sumofcubes==original;
}
int main(){
    if(isarmstrong(153)){
        cout<<"number is armstrong number";
    }
    else{
     cout<<"the given number is not armstrong number";
    }
    return 0;
}