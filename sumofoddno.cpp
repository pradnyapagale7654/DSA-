#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"enter the n:"<<endl;
    cin>>n;
    int sum=0;
    for(i=1;i<n;i++){
    if(i%2!=0){
        sum=sum+i;
         }
        }
         cout<<"sum of all odd numbers upto n is:"<<sum<<endl;
        
    return 0;
}