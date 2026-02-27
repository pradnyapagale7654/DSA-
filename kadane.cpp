#include<iostream>
#include <climits>    // For INT_MIN
#include <algorithm>
using namespace std;
int main(){
    int i,j,n;
    int arr[100];
    cout<<"enter size:";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int cs=0;
    int maxsum=INT_MIN;
    for(i=0;i<n;i++){
     cs=cs+arr[i];
     maxsum=max(cs,maxsum);
     if(cs<0){
        cs=0;
     }
}
cout<<"maximum sum of subarray is:"<<maxsum;
return 0;
}