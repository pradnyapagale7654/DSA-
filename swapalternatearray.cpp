#include<iostream>
#include<algorithm>
using namespace std;
void swapalternate(int arr[],int n){
for(int i=0;i<n;i+=2){
    if(i+1<n){ //next element is there
    swap(arr[i],arr[i+1]);
    }
}
}
void print(int arr[],int n){
    cout<<"array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
int main(){
    int arr[5]={1,5,3,9,7};
    int n=5;
     swapalternate(arr,n);
    print(arr,n);
    return 0;
}