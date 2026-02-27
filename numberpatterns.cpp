#include<iostream>
using namespace std;
int main(){
    int i,n;
    int j;
    n=4;
    for(i=0;i<4;i++){
        for(j=1;j<=4;j++){//square pattern
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}
int main(){
    int i,j,n;
    n=3;
    int num=1;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<num<<" ";//square pattern with increment
            num++;
        }
        cout<<endl;
    }
    return 0;
}
//triangle pattern   1 22 333 4444
int main(){
int i,j,n;
n=4;
for(i=0;i<n;i++){
    for(j=0;j<i+1;j++){
        cout<<i+1;
    }
    cout<<endl;
}
return 0;
}