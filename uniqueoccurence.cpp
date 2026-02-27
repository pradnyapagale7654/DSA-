#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class solution{
    public:
bool isunique(vector<int>&arr){
unordered_map<int,int>freq;
unordered_set<int>s;
for(int num : arr){
freq[num]++;
}
for(auto & p:freq){
    s.insert(p.second);
}
return s.size()==freq.size();
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
     if(s.isunique(arr)) {
         cout << "Frequencies are unique." << endl;
         } 
         else { 
            cout << "Frequencies are NOT unique." << endl;
         }
         return 0;
}
