#include <iostream>
using namespace std;
int main() {
int i,j,n,arr[100];
cout<<"enter array size:"<<endl;
cin>>n;

cout<<"enter array elements:"<<endl;
for(i=0;i<n;i++){
    cin>>arr[i];
}
int pivot=arr[0];
i=1;
j=n-1;
while(i<=j){
    while(i<n && arr[i]<pivot){
        i++;
    }
    while(j>=0 && arr[j]>pivot){
        j--;
    }
    if (i < j) { swap(arr[i], arr[j]); i++; j--; }
   
}
swap(arr[0],arr[j]);
cout << "sorted array elements are: ";
for (int k = 0; k < n; k++) {
    cout << arr[k];
 if (k + 1 < n) 
 cout << " "; 
 else 
 cout << "\n";
}

    return 0;}