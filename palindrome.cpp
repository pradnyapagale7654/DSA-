#include<iostream>
using namespace std;
class solution{
    public:
    bool isprime(int x){
        if(x<0){
            return false;
        }
        long rev=0;
        int original=x;
        while(x!=0){
            rev=rev*10+x%10;
            x=x/10;
        }
        if(rev==original){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    solution s;
    int nums=454;

    cout<<s.isprime(nums);
    return 0;
}