#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    bool ispossible(vector<int>arr,int m,int n,int mid){
        int pagesum=0;
        int studentcount=1;
        for(int i=0;i<n;i++){
            if(pagesum+arr[i]<=mid){
              pagesum+=arr[i];
            }
            else{
                studentcount++;
                if(studentcount>m || arr[i]>mid){
                    return false;
                }
                pagesum=arr[i];
            }
        }
        return true;
    }
    int bookallocation(vector<int>arr,int m,int n){
     int st=0;
     int sum=0;
     for(int i=0;i<n;i++){
        sum=sum+arr[i];
     }
     int end=sum;
     int ans=-1;
     int mid=st+(end-st)/2;
     while(st<=end){
        if(ispossible(arr,m,n,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
        mid=st+(end-st)/2;
     }
     return ans;
    }
};
int main(){
    solution s;
    vector<int>arr={10,20,30,40};
    int m=2;
    int n=4;
    int result=s.bookallocation(arr,m,n);
    cout<<result;
    return 0;
}