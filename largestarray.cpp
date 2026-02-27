#include<iostream>
using namespace std;
int main(){
    int i,n;
    int a[100];
    cout<<"enter the size of an array:"<<endl;
    cin>>n;
    cout<<"enter the array elements:"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int largest=a[0];
    for(i=0;i<n;i++){
        if(a[i]>largest){
            largest=a[i];

        }
    }
    cout<<"largets element is :"<<largest<<endl;


    return 0;
}