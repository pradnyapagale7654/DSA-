#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;
    cout << "Before Swap: a = " << a << ", b = " << b << endl;

    a = a ^ b; // Step 1
    b = a ^ b; // Step 2
    a = a ^ b; // Step 3

    cout << "After Swap (using XOR): a = " << a << ", b = " << b << endl;
    return 0;
}
