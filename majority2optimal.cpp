#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    vector<int>majorityElement(vector<int>& nums) {
    int n=nums.size();
    int ans1=0;
    int count1=0;
    int ans2=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(count1==0){
            ans1=nums[i];
            count1=1;
        }
        else if(ans1==nums[i]){
            count1++;
        }
        else if(count2==0){
            ans2=nums[i];
            count2=1;
        }
        else if(ans2==nums[i]){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    // gaurantee that the ans1 and ans2 are the majority elements
    count1=0;
    count2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ans1){
            count1++;
        }
        else if(nums[i]==ans2){
            count2++;
        }
    }
    vector<int>ans;
    if(count1>n/3){
        ans.push_back(ans1);
    }
    if(count2>n/3){
        ans.push_back(ans2);
    }
    return ans;
}
};
int main(){
    solution s;
    vector<int>nums={3,2,3};
    vector<int>ans=s.majorityElement(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}