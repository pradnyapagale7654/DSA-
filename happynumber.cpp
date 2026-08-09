#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class solution{
    public:
int getnext(int n){
    int sum=0;
    while(n>0){
        int digits=n%10;
        sum+=digits*digits;
        n=n/10;
    }
    return sum;
}
bool ishappy(int n){
    unordered_set<int>st;
    while(n!=1){
        if(st.count(n)){
            return false;    // if n is alrady present in set then false
        }
        st.insert(n);  // insert n in set
        n=getnext(n);  // get next number and store it in n so that for further iteration we can check if it is present in set or not
    }
    return true;
}
};
int main(){
    solution s;
    int n;
    cout<<"enter the number to check if it is happy or not: ";
    cin>>n;
    if(s.ishappy(n)){
        cout<<n<<" is a happy number";
    }
    else{
        cout<<n<<" is not a happy number";
    }
    return 0;
}