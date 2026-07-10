#include<iostream>
#include<vector>
using namespace std;
 // to find the nth element in the pascal triangle we find the nCr
 // so for that used formula 
 int fact(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
 }
 int ncr(int row,int col){  //n=row r=col
int fact_row=fact(row);
int fact_col=fact(col);
int fact_n_r=fact(row-col);
return fact_row/(fact_col*fact_n_r);
 }
 int main(){
    int row,col;
    cout<<"enter row:";
    cin>>row;
    cout<<"enter col:";
    cin>>col;
    int nthelement=ncr(row-1,col-1);
    cout<<"nth element in pascals triangle is:"<<nthelement;
    return 0;
 }