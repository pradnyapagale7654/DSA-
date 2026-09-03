#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
char smallestletter(vector<char>& letters,char target){
    int n=letters.size();
  int st=0;
  int end=n;
  while(st<end){
    int mid=st+(end-st)/2;
    if(letters[mid]>target){
        end=mid;
        }
        else{
        st=mid+1;
    }
  }
  return letters[st % n]; // This line ensures that if st equals n, it wraps around to the first element of the array.
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