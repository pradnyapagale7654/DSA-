#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    void mergedarray( vector<int>&a,vector<int>&b,int n,int m){
        int idx=m+n-1;
        int i=m-1;
        int j=n-1;
        while(i>=0 && j>=0){
            if(a[i]>=b[j]){
                a[idx]=a[i];
                idx--;
                i--;
            }
            else{
                a[idx]=b[j];
                idx--;
                j--;
            }
        }
        while(j>=0){
            a[idx]=b[j];
            idx--;
            j--;
        }
    }
};
int main(){
    solution s;
    vector<int>a={1,2,3,0,0,0};
    vector<int>b={4,5,7};
    int m=3;
    int n=b.size();
    s.mergedarray(a,b,m,n);
    cout<<"array after merging:"<<endl;
    for(int x:a){
        cout<<x<<endl;
    }
    return 0;
}
