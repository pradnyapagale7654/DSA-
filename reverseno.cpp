#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    int reverse=0;
    cout<<"enter element:"<<endl;
    cin>>n;
    while(n!=0){
        reverse=reverse*10+n%10;
        n=n/10;
    }
    cout<<"reversed element is:"<<reverse;
    return 0;
}