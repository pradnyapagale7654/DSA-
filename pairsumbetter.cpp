#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    int arr[100];
    cout<<"enter the array size:"<<endl;
    cin>>n;
    cout<<"enter the array elemenets:";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    cout<<"sorted array is:";
    for(i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
    int target;
    cout<<"enter target:"<<endl;
    cin>>target;
    int smallest=0;
    int largest=n-1;
    while (smallest < largest){
        if(arr[smallest]+arr[largest]==target){
          cout<<"pair sum is:"<<arr[smallest]<<" "<<arr[largest];
          return 0;
        }
        else if(arr[smallest]+arr[largest]<target){
            smallest++;
        }
        else{
            largest--;
        }
    }
    return 0;
}