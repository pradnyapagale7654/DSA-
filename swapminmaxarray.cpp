#include<iostream>
#include<algorithm>
using namespace std;
void swapminmax(int arr[],int n){
int minidx=0;
int maxidx=0;
for(int i=0;i<n;i++){
    if(arr[i]>arr[maxidx]){
        maxidx=i;
    }
    if(arr[i]<arr[minidx]){
        minidx=i;
    }
}
int temp=arr[minidx];
arr[minidx]=arr[maxidx];
arr[maxidx]=temp;
}
int main(){
    int i,n,arr[100];
    cout<<"enter size:"<<endl;
    cin>>n;
    cout<<"enter array elements:"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"before swapping min and max:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    swapminmax(arr,n);
    cout<<"max and min after swapping array becomes:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}