#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"enter the value of n:"<<endl;
    cin>>n;
    for(i=2;i<=n-1;i++){
        if(n%i==0){
            cout<<"number is not prime"<<endl;
            break;
        }
        else{
            cout<<"number is prime"<<endl;
        }
    }
}

/*or
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n;
    bool isprime=true;
    cout<<"entre n:";
    cin>>n;
    if(n<=1){
        isprime=false;
    }
    else{
        for(int i=2;i<=sqrt(n);i++){
            if(n%1==0){
                isprime=false;
                break;
            }
         
        }
    }
    if(isprime){
        cout<<"prime";
    }
    else{
        cout<<"not prime";
    }
} 
    */