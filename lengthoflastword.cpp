#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
int lengthoflastword(string s){
    int count=0;
    //skip the spaces if at last 
    int i=s.size()-1;
    while(i>=0 && s[i]==' '){
        i--;
    }
    //count if no spaces
    while(i>=0 && s[i]!=' '){
        count++;
        i--;
    }
    return count;
}
};
int main(){
    solution st;
    string s=" fly me to the  word  ";
    int ans=st.lengthoflastword(s);
    cout<<"length of last word in a string:"<<ans;
    return 0;
}