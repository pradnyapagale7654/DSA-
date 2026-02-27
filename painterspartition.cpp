#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class solution{
    public:
    bool ispossible(vector<int>arr,int m,int n,int mid){
        int time=0;
        int painter=1;
        for(int i=0;i<n;i++){
            if(time+arr[i]<=mid){
                time+=arr[i];
            }
            else{
                painter++;
                if(painter>m || arr[i]>mid){
                    return false;
                }
                time=arr[i];
            }
        }
        return true;
    }
    int mintimetopaint(vector<int>arr,int m,int n){
     int sum=0;
     int maxval=INT_MIN;
     for(int i=0;i<n;i++){
        sum=sum+arr[i];
        maxval=max(maxval,arr[i]);
     }
     int st=maxval;
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
    int result=s.mintimetopaint(arr,m,n);
    cout<<result;
    return 0;
}