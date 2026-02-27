#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;
    cout << "Before Swap: a = " << a << ", b = " << b << endl;
   //without using temp variable
    a = a + b;
    b = a - b;
    a = a - b;
   /*using temp variable
   int temp=a
   a=b;
   b=temp
   */
  /*
  without using temp variable and third variable 
  using EXOR operation
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
  */
    cout << "After Swap (no temp, using arithmetic): a = " << a << ", b = " << b << endl;
    return 0;
}
