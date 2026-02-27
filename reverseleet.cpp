#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;//if reverse no is large i.e out of limit 32 bit then return 0
int main(){
    int i,j,n;
    cout<<"enter number:"<<endl;
    cin>>n;
    int rev=0;
    while(n!=0){
       if((rev>INT_MAX/10) || (rev<INT_MIN/10)){ // returns 0 if element is largest
        return 0;
       }
       rev=rev*10+n%10;
       n=n/10;
    }
    cout<<rev;
    return 0;
}