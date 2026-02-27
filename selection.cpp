#include<iostream>
#include<algorithm>
using namespace std;
void selection(int arr[],int n){
   for(int i=0;i<n;i++){
    int smallestidx=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[smallestidx]){
            smallestidx=j;
        }}
        swap(arr[i],arr[smallestidx]);
    
   }
}
void printsort(int arr[],int n){
   for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
   }  
}
int main(){
    int n=5;
    int arr[]={4,3,1,7,9};
    selection(arr,n);
    printsort(arr,n);
    return 0;
}