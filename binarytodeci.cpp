#include<iostream>
using namespace std;
int bintodeci(int bin){
    int ans=0;
    int pow=1;
    while(bin>0){
        int rem=bin%10;
        bin=bin/10;
        ans=ans+(rem*pow);
        pow=pow*2;
    }
    return ans;
}
int main(){
    int result=bintodeci(101);
    cout<< " binary to decimal is:"<<result;
    return 0;
}




