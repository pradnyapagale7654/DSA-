
    #include <iostream>
    using namespace std;
    
    int main() {
        int a = 5, b = 10;
        cout << "Before Swap: a = " << a << ", b = " << b << endl;
    
        int temp = a;
        a = b;
        b = temp;
    
        cout << "After Swap (using temp): a = " << a << ", b = " << b << endl;
        return 0;
    }
    
    