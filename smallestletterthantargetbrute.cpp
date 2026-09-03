#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
char smallestletter(vector<char>& letters,char target){
    int n=letters.size();
    for(int i=0;i<n;i++){
        if(letters[i]>target){
            return letters[i];
        }
    }
    return letters[0];
}
};
int main(){
    solution s;
    vector<char>letters={'c','f','j'};
    char target='a';
    char res=s.smallestletter(letters,target);
    cout<<"The smallest letter greater than target is: "<<res<<endl;
    return 0;
}