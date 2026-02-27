#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    cout<<"vector size:"<<v.size();
    cout<<"vector capacity:"<<v.capacity();
    v.push_back(3);
    v.push_back(5);
    v.pop_back();
    v.resize(8);
    cout<<"vector size:"<<v.size();
    cout<<"vector capacity:"<<v.capacity();
    return 0; 
}