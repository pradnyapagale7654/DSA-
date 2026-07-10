#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
vector<int>pairsum(vector<int>&arr,int tar){
   unordered_map<int,int>m;
   int n=arr.size();
   for(int i=0;i<n;i++){
      int first=arr[i];
      int sec=tar-first;
      if(m.find(sec)!=m.end()){
        return {i,m[sec]};
      }
      m[first]=i;
   }
   return {};
    }
};
int main(){
    solution s;
    vector<int>arr={1,6,2,8,4};
    int tar=12;
    vector<int>result=s.pairsum(arr,tar);
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
    return 0;
}