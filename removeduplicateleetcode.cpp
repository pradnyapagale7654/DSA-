#include <iostream>
#include<vector>
using namespace std;
class solution{
 public:
int removeduplicate(vector<int>&arr){
    int n=arr.size();
    int i=1;
    for(int k=1;k<n;k++){
        if(arr[k]!=arr[k-1]){
            arr[i]=arr[k];
            i++;
        }
    }
    return i;
}
};
int main(){
    solution s;
    vector<int>arr={1,2,3,3,4,4,5,6,6};
    int ans=s.removeduplicate(arr);
    cout<<"total no of unique elements are:"<<ans;
    return 0;
}