#include<iostream>
using namespace std;
int main(){
    int i,j,n,a[100];
    cout<<"enter size:"<<endl;
    cin>>n;
    cout<<"enter array elements:"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(i=0;i<n;i++){
        sum=sum+a[i];
    }
    cout<<"sum of array element is :"<<sum<<endl;
    return 0;
}