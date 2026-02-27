
#include <iostream>

#include <vector>

using namespace std;


void quicksort(vector<int>&a,int f,int l){

if(f<l){

    int pivot=a[f],i,j,temp;

    i=f+1;

    j=l;


    while(i<=j){

         while(i<=l && a[i]<pivot)  i++;

         while(j>=f && a[j]>pivot)  j--;


         if(i<j){

            temp=a[i];           

            a[i]=a[j];

            a[j]=temp;

    

            i++;

            j--;

         }

        }

            a[f] = a[j];   

            a[j] = pivot; 


            quicksort( a,f, j-1);

            quicksort(a,j+1, l);

    }

}


        


int main(){

    cout<<"WAREHOUSE MANAGEMENT SYSTEM"<<endl;

    int n;

    cout<<"Enter the number of inventory items:";

    cin>>n;


    vector<int>a(n);

    for(int i=0;i<n;i++){

        cout<<"Enter the quantity of item "<<i+1<<":";

        cin>>a[i];

    }


    cout<<endl;


    cout<<"BEFORE SORTING:";

    for(int i=0;i<n;i++){

        cout<<"\n Quantity of item "<<i+1<<":";

      cout<<a[i];

    }

    cout<<endl;


    int f=0;

    int l=n-1;


    quicksort(a,f,l);


    cout<<"\n AFTER SORTING:"<<endl;

    for(int i=0;i<n;i++){

        cout<<"Quantity of item "<<i+1<<":";

     cout<<a[i]<<endl;

    }


    return 0;



}