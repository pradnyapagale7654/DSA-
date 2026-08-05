#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
class solution{
    public:
vector<int>plusone(vector<int>&digits){
    int n=digits.size();
    for(int i=n-1;i>=0;i--){
        if(digits[i]<9){
            digits[i]++;
            return digits;
        }
        // else equal to 9 
        digits[i]=0; 
    }
    // here now we have [0,0,0] if input is [9,9,9]
    digits.insert(digits.begin(),1); // create one idx and insert 1 in it
    return digits;
}
};
int main(){
    solution s;
    vector<int>digits={9,9,9};
    vector<int>ans=s.plusone(digits);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}