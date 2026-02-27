#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>&a,int l,int m,int r){

int n1=(m-l)+1;              

int n2=r-(m+1)+1;    
int left[n1],right[n2];

for(int i=0;i<n1;i++)

left[i]=a[l+i];

for(int j=0;j<n2;j++)

right[j]=a[m+1+j];

int i=0,j=0,k=l;   
while(i<n1  && j<n2){

 if (left[i] <= right[j]) {

   a[k]=left[i];

   i++;

   }

   else{

   a[k]=right[j];

   j++;

   }
   k++;

   }
 while(i<n1){

   a[k]=left[i];

   i++;

   k++;

   }
while(j<n2){

     a[k]=right[j];

       j++;

       k++;

       }

       }
void mergeSort(vector<int>&a,int l,int r){

if(l<r){

int m=l+(r-l)/2;     
mergeSort (a,l,m);       
mergeSort (a,m+1,r);
merge(a,l,m,r) ;    
}
}
int main(){

cout<<"------USER'S TRANSACTION HISTORY-------\n"<<endl;

int n;

cout<<"Enter the number of transactions:";

cin>>n;
vector<int>a(n);

for(int i=0;i<n;i++){

cout<<"Enter the transaction amount "<<i+1<<":";

cin>>a[i];

}

 cout << endl;
cout<<"BEFORE SORTING :"<<endl;

for(int i=0;i<n;i++){

cout<<"TRANSACTION AMOUNT "<<i+1<<":"<<a[i]<<endl;

}

cout << endl;


mergeSort(a,0,n-1);


cout<<"AFTER SORTING:"<<endl;

for(int i=0;i<n;i++){

cout<<"TRANSACTION AMOUNT "<<i+1<<":"<<a[i]<<endl;

}

cout << endl;


return 0;

}