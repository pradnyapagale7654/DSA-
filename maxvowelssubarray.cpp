#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
bool isvowel(char c){  //check for the vowels
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
int maxcountvowelsubarray(string s,int k){
    int n=s.size();
    int count=0;
    //for the first window
    for(int i=0;i<k;i++){
        if(isvowel(s[i])){
            count++;
        }
    }
    int maxcount=count; //initialize the maxcount
    //slide the window
    for(int i=k;i<n;i++){
        // remove the older element if it is vowel
        if(isvowel(s[i-k])){
            count--;
        }
        // add the new element if it is vowel
        if(isvowel(s[i])){
            count++;
        }
        maxcount=max(maxcount,count); //update the maxcount
    }
    return maxcount;
}

};
int main(){
    solution s;
    string str="abciiidef";
    int ans=s.maxcountvowelsubarray(str,3);
    cout<<"max count of vowels in subarray:"<<ans;
    return 0;
}