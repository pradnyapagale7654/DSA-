#include<iostream>
using namespace std;
class solution{
    public:
bool issquare(int c){
    for(long long i=0;i*i<=c;i++){
        for(long long j=0;j*j<=c;j++){
            if(i*i+j*j==c){
                return true;
            }
        }
    }
    return false;
}
};
int main(){
    solution s;
    int c=5;
    cout<<s.issquare(c);
    return 0;
}