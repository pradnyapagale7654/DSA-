#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
   int peakindex(vector<int>&arr){
    int n=arr.size();
    int st=1;
    int end=n-2;
    while(st<=end){
       int mid=st+(end-st)/2;
       if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
        return mid;
       } 
       if(arr[mid-1]<arr[mid]){
        st=mid+1;
       }
       else{
        end=mid-1;
       }
    }
    return -1;
   }
};
int main(){
    solution s;
    vector<int>arr={3,5,7,9,6,1};
    cout<<s.peakindex(arr);
    return 0;
}