#include <iostream>

#include <vector>

using namespace std;



void insertsort(vector <int>&a,int n){

    for(int i=1;i<n;i++){

        int curr=a[i];

        int prev=i-1;


      while(prev>=0 && a[prev]<curr){

        a[prev+1]=a[prev];

        prev--;

    }

    a[prev+1]=curr;

}

}


int main(){

    cout<<"MERIT LIST OF STUDENTS"<<endl;

    int n;

    cout<<"Enter the number of students:";

    cin>>n;


    vector<int>a(n);

    for(int i=0;i<n;i++){

    cout<<"Enter the score of Student "<<i+1<<":";

    cin>>a[i];

}

  cout<<endl;


  cout<<"\nBEFORE  SORTING:"<<endl;

   for(int i=0;i<n;i++){

    cout<<"Student Score "<<i+1<<":";

    cout<<a[i]<<endl;

   }


 insertsort(a,n);


 cout<<"\nAFTER SORTING:"<<endl;

   for(int i=0;i<n;i++){

    cout<<"Student Score "<<i+1<<":";

    cout<<a[i]<<endl;

   }


}