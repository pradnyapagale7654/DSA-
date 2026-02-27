// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
int a,b;
cin>>a>>b;
string word[]={"one","two","three","four","five","six","seven","eight","nine"};
for(int i=a;i<=b;i++){
    if(i>=1 && i<=9){
        cout<<"\n"<<word[i-1];
    }
    else if(i%2==0){
        cout<<"\n even";
    }
    else{
        cout<<"\n odd";
    }
}
    return 0;
}