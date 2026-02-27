#include <iostream>
using namespace std;
int main() {
    int i,j,n,arr[100];
    cout<<"enter size:"<<endl;
    cin>>n;
    cout<<"entre array elements:"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                for(int k=j;k<n-1;k++){
                    arr[k]=arr[k+1];
                }
                n--;
                j--;
            }
        }
    }
    return 0;
}