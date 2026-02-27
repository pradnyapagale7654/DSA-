#include<iostream>
#include<vector>
using namespace std;
// to find how many numbers are prime in between the given range we use most optimal path that is sieve of eratosthenes
int countprime(int n){
    vector<bool>isprime(n,true);
    int count=0;
    for(int i=2;i<n;i++){
        if(isprime[i]){ //prime so count it
            count++;
            for(int j=i*2;j<n;j=j+i){ //not a prime
                isprime[j]=false;
            }
        }
    }
    return count;
}
int main(){
    cout<<countprime(9);
    return 0;
}