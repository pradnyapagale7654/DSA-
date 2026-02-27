/*
#include<iostream>
using namespace std;
int linear(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
       
    }
    return -1;
}
int main(){
    int arr[]={2,4,6,8,9};
    int key=6;
    int n=5;
    int ans=linear(arr,n,key);
    cout<<ans;
    return 0;
}
*/
#include<iostream>
using namespace std;
int main(){
    int i,j,n,a[100];
    cout<<"enter size:"<<endl;
    cin>>n;
    cout<<"enter array elements:"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cout<<"enter key element which is to be searched:"<<endl;
    cin>>key;
    for(i=0;i<n;i++){
        if(a[i]==key){
            cout<<"element is present at index:"<<i+1<<endl;
            break;
        }
    }
    if(i==n){
        cout<<"element is not present :"<<endl;
    }
    return 0;
}