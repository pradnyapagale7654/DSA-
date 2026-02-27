#include<iostream>
using namespace std;
int main(){
    int i,n,a[100];
    cout<<"enter size:"<<endl;
    cin>>n;
    cout<<"enter array elements:"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    /* without using swapping i.e using two pointer approach
    int st=0;
    int end=n-1;
    while(st<end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }*/
   // below logic is by using swapping 
    for(i=0;i<n/2;i++){
        int tem=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=tem;
    }
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
