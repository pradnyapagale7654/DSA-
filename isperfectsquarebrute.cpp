#include<iostream>
using namespace std;
class solution{
    public:
bool isperfectsquare(int num){
    if(num<0){ //if the number is negative then it cannot be a perfect square
        return false;
    }
    for(long long i=0;i<=num;i++){
        if(i*i==num){ //if the square of i is equal to num then it is a perfect square
            return true;
        }
    }
    return false;
}
};
int main(){
    solution s;
    int num=16;
    bool res=s.isperfectsquare(num);
    if(res){
        cout<<num<<" is a perfect square number."<<endl;
    }
    else{
        cout<<num<<" is not a perfect square number."<<endl;
    }
    return 0;
}