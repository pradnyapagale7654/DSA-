#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    bool ispossible(vector<int>&arr,int n,int c,int mid){
        int cowscount=1;
        int lastpos=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-lastpos>=mid){
                //can place the cows
                cowscount++;
                lastpos=arr[i];
            }
            if(cowscount==c){
                return true;
            }
        }
        return false;
    }
    int getdistance(vector<int>&arr,int n,int c){
        sort(arr.begin(),arr.end());
        int st=1;
        int end=arr[n-1]-arr[0];
        int ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(ispossible(arr,n,c,mid)){
                ans=mid;
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};
int main(){
    solution s;
    vector<int>arr={10,20,30,40};
    int c=2;
    int n=4;
    int result=s.getdistance(arr,n,c);
    cout<<result;
    return 0;
}