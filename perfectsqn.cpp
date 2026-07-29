#include <iostream>
using namespace std;
class solution{
    public:
  void perfectsquare(int n){
      int i=1;
      int sq;
      while(i*i<n){
          cout<<i*i<<endl;
          i++;
          
      }
  }  
};
int main() {
    solution s;
    int n=20;
    s.perfectsquare(n);

    return 0;
}