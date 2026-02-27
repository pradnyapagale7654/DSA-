#include <iostream>
using namespace std;

class Stack {
    char arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(char ch) {
        if (top < 99)
            arr[++top] = ch;
    }

    char pop() {
        if (top >= 0)
            return arr[top--];
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

string reverseString(string str) {
    Stack s;
    for (int i = 0; i < str.length(); i++)
        s.push(str[i]);

    string rev = "";
    while (!s.isEmpty())
        rev += s.pop();

    return rev;
}

int main() {
    string input = "Pradnya";
    string output = reverseString(input);

    cout << "Original: " << input << endl;
    cout << "Reversed: " << output << endl;

    return 0;
}
