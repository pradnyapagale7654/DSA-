#include<iostream>
using namespace std;
int dectobinary(int decnum){
int pow=1;
int ans=0;
while(decnum>0){
    int rem=decnum%2;
    decnum=decnum/2;
    //reverse the remainders and store it in ans
    ans=ans+(pow*rem);
    pow=pow*10;
}
return ans;
}
int main(){
    int result=dectobinary(5);
    cout<< "decimal to binary is:"<<result;
    return 0;
}