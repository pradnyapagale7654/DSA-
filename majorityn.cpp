#include<iostream>
using namespace std;
int main(){
    int i,j,n,arr[100];
    cout<<"enter size:"<<endl;
    cin>>n;
    cout<<"enter array elements:"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        int count=0;
        for(j=0;j<n;j++){
           if(arr[i]==arr[j]){
            count++;
            
           }
        }
        if(count>n/2){
            cout<<"majority element is:"<<arr[i];
            return 0;                           //once we find the majority element then we have to stop here so return 0
        }
    }
    return 0;
}