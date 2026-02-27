#include<iostream>
using namespace std;
int main(){
    int i,j,sum,n;
    sum=0;
    int target;
    int arr[100];
    cout<<"enter array size:"<<endl;
   cin>>n;
   cout<<"enter array elements:"<<endl;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   cout<<"enter the target:";
   cin>>target;
   bool found=false;
   for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
       if(arr[i]+arr[j]==target){
        cout<<"pair  is found :("<<arr[i]<<","<<arr[j]<<")at indices:"<<i<<" "<<j;
        found=true;
       }
    }
   }
   if(!found){
    cout<<"pair sum is not found"<<endl;
   }
   return 0;
}