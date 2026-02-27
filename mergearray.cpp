#include<iostream>
#include<vector>
using namespace std;
vector<int>mergedarray(const vector<int>&a,const vector<int>&b){
    vector<int>result;
    int i=0;
    int j=0;
    // traverse both arrays
    while(i<a.size() && j<b.size()){
         if(a[i]<b[j]){
            if(result.empty() || result.back()!=a[i]){
                result.push_back(a[i]);
                i++;
            }
         }
         else if (a[i]>b[j]){
            if(result.empty() || result.back()!=b[j]){
                result.push_back(b[j]);
                j++;
            }
         }
         else{
            // equal
            if(result.empty() || result.back()!=a[i]){
                result.push_back(a[i]);
                i++;
                j++;
            }
         }
    }
    // add remaining elements
    while(i<a.size()){
        if(result.empty() || result.back()!=a[i]){
            result.push_back(a[i]);
            i++;
        }
    }
    while(j<b.size()){
        if(result.empty() || result.back()!=b[j]){
            result.push_back(b[j]);
            j++;
        }
    }
    return result;
}