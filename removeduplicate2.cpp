#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
int removeduplicate(vector<int>&arr){
    int n=arr.size();
    int k=2;   // k used for counting unique elements and for placing them in the correct position in the array
    for(int i=2;i<n;i++){
        if(arr[i]!=arr[k-2]){
            arr[k]=arr[i];
            k++;
        }
    }
    return k;
}
};
int main(){
    solution s;
    vector<int>arr={1,1,1,2,2,3};
    int ans=s.removeduplicate(arr);
    cout<<"total no of unique elements are:"<<ans;
    return 0;
}