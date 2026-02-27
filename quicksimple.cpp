// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int partition(int arr[],int low,int high){
        int piv=arr[low];
        int i=low;
        int j=high;
    while(i<j){
        while(arr[i]<=piv){
            i++;
        }
        while(arr[j]>piv){
            j--;
        }
        if(i<j){
           swap(arr[i],arr[j]);
        }
    }
 swap(arr[low],arr[j]);
    return j;
}
void quick(int arr[],int low,int high){
    if(low<high){
        int location=partition(arr,low,high);
        quick(arr,low,location-1);
        quick(arr,location+1,high);
    }
}
int main() {
    int arr[]={1,4,23,7,65};
    int n=5;
    int lb=0;
    int ub=n-1;
    quick(arr,lb,ub);
    cout<<"sorted array is:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}