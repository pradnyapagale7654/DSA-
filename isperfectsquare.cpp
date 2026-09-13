#include<iostream>
using namespace std;
class solution{
    public:
bool isperfectsquare(int num){
    long long left=0;
    long long right=num;
    while(left<=right){
        long long mid=left+(right-left)/2;
        if(mid*mid==num){ //if the square of mid is equal to num then it is a perfect square
            return true;
        }
        else if(mid*mid<num){ //if the square of mid is less than num then we need to search in the right half
            left=mid+1;
        }
        else{ //if the square of mid is greater than num then we need to search in the left half
            right=mid-1;
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