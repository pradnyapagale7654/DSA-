#include<iostream>
#include<cmath>
using namespace std;
class solution{
    public:
    bool judgesquaresum(int num){
        long long left=0;
        long long right=num;
        while(left<=right){
            if(left*left+right*right==num){ //if the sum of squares of left and right is equal to num then it is a perfect square sum
                return true;
            }
            else if(left*left+right*right<num){ //if the sum of squares of left and right is less than num then we need to search in the right half
                left++;
            }
            else{ //if the sum of squares of left and right is greater than num then we need to search in the left half
                right--;
            }
        }
        return false;
    }
};
int main(){
    solution s;
    int num=5;
    bool res=s.judgesquaresum(num);
    if(res){
        cout<<num<<" can be expressed as the sum of squares of two integers."<<endl;
    }
    else{
        cout<<num<<" cannot be expressed as the sum of squares of two integers."<<endl;
    }
    return 0;
}