#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    void printrow(int n){
        int ans=1;
        for(int i=1;i<=n;i++){
            cout<<ans<<" ";
           ans=ans*(n-i)/i;  // n=row and i=col
        }
        cout<<endl;

    }
};
int main(){
    
    int n;
    cout<<"enter row:";
    cin>>n;
    solution s;
    s.printrow(n);
    return 0;
}