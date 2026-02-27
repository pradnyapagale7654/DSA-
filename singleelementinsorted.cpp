#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    int singleelement(vector<int>&arr){
       int n=arr.size();
       int st=0;
       int end=n-1;
       if(n==1){
        return arr[0];
       }
       while(st<=end){
       int mid=st+(end-st)/2;
       if(mid==0 && arr[0]!=arr[1]){
       return arr[0];
       }
       if(mid==n-1 && arr[n-1]!=arr[n-2]){
        return arr[n-1];
       }
       if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
        return arr[mid];
       }
       if(mid%2==0){
        if(arr[mid]==arr[mid-1]){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
       }
       else{
        if(arr[mid]==arr[mid-1]){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
       }
       }
       return -1;
    }
};
int main(){
    solution s;
    vector<int>arr={1,1,2,2,3,3,4,5,5,6,6,7,7};
    cout<<s.singleelement(arr);
    return 0;
}