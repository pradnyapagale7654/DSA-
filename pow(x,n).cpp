#include<iostream>
using namespace std;
class solution{
    public:
    double mypower(double x,int n){
        long long bf=n;
        double ans=1;
    if(bf<0){
      x=1.0/x;
      bf=-bf;
    }
    while(bf>0){
        if(bf%2==1){  //check wheather exponent is odd if yes then
        ans=ans*x;
    }
    x=x*x;    // if exponent is even
    bf=bf/2;
    }
    return ans;
}
};
int main(){
    solution s;
    cout<<s.mypower(2,5);
    return 0;
}