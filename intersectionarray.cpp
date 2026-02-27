#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
vector<int>intersection(vector<int>&num1,vector<int>&num2){
    vector<int>ans;
    int n1=num1.size();
    int n2=num2.size();
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(num1[i]==num2[j]){
                if(find(ans.begin(),ans.end(),num1[i])==ans.end()){   // no element already present so insert avoid duplicates
                    ans.push_back(num1[i]);
                }
                break;
            }
        }
    }
    return ans;
}
};
int main(){
    solution s;
    vector<int>num1={1,2,3,4,5};
    vector<int>num2={6,2,9,4};
    int n1=5;
    int n2=4;
    vector<int>result=s.intersection(num1,num2);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}