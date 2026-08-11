#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class solution{
    public:
bool isduplicate(vector<int>&nums){
    unordered_set<int>st;
    for(int x:nums){
        if(st.count(x)){
            return true;
}
st.insert(x);
    }
    return false;
}
};
int main(){
    solution s;
    vector<int>nums={1,2,3,4,5};
    if(s.isduplicate(nums)){
        cout<<"The array contains duplicate elements."<<endl;
    }
    else{
        cout<<"The array does not contain duplicate elements."<<endl;
    }
    return 0;
}