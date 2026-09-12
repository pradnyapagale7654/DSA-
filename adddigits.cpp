#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
int adddigits(int num){
    while(num>=10){ //repeat until we dont get the single digit number
    int sum=0;
    while(num>0){
        sum=sum+num%10; //add the last digit to sum
        num=num/10; //remove the last digit from num
    }
    num=sum; //update num to sum
    }
    return num; //return the single digit number
}
};
int main(){
    solution s;
    int num=38;
    int res=s.adddigits(num);
    cout<<"The single digit number is: "<<res<<endl;
    return 0;
}