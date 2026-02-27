#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int i,j,n,arr[100];
    cout<<"enter size:"<<endl;
    cin>>n;
    cout<<"enter the array elements:";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
             swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"ans is:";
    for(i=0;i<n;i++){
    cout<<arr[i];
    }
    return 0;
}