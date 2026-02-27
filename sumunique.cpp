#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class solution{
    public:
    int sumofunique(vector<int>&arr){
        unordered_map<int,int>freq;
        for(int num:arr){
            freq[num]++;
        }
        int sum=0;
        //check whether freq is 1 if yes then sum +=element i.e p.first
        for(auto &p:freq){
            if(p.second==1){
                sum=sum+p.first;
            }
        }
        return sum;
    }
};
int main(){
    solution s;
    int n; 
     cout << "Enter number of elements: "; 
     cin >> n;
     vector<int> arr(n);
     cout << "Enter elements: "; 
     for(int i = 0; i < n; i++) { 
        cin >> arr[i];
     }
     int result=s.sumofunique(arr);
     cout<<"sum of unique elements is:"<<result;
     return 0;
}