#include <iostream>
#include <string>
using namespace std;
class intstack {
public:
    int top1;
    int stck[30];

    intstack() {
        top1 = -1;
    }
   void push(int val) {
        if (top1 == 29) {
            cout << "Stack overflow\n";
            return;
        }
        stck[++top1] = val;
    }
    int pop() {
        if (top1 == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return stck[top1--];
    }
};

class charstack {
public:
    int top2;
    char stck1[20];
    charstack() {
        top2 = -1;
    }
   void push(char val) {
        if (top2 == 19) {
            cout << "Stack overflow\n";
            return;
        }
        stck1[++top2] = val;
    }
    char pop() {
        if (top2 == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return stck1[top2--];
    }
};
bool isoperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'){
        return true;
    }
}
int prec(char c){
    if(c=='*'|| c=='/'){
        return 2;
    }
    else if(c=='+'|| c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
int op(int t1, char t2, int t3) {
    switch (t2) {
        case '+': return t1 + t3;
        case '-': return t1 - t3;
        case '*': return t1 * t3;
        case '/': return t1 / t3;
        default: return 0;
    }
}
int evaluateinfix(string s) {
    intstack a;
    charstack b;
   for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!isoperator(c)) {
            a.push(c - '0');
        } else if (isoperator(c)) {
            while (b.top2 != -1 && prec(b.stck1[b.top2]) >= prec(c)) {
                int t1 = a.pop();
                int t3 = a.pop();
                char t2 = b.pop();
                a.push(op(t3, t2, t1));
            }
            b.push(c);
        }
    }
    while (b.top2 != -1) {
        int t1 = a.pop();
        int t3 = a.pop();
        char t2 = b.pop();
        a.push(op(t3, t2, t1));
    }
   return a.pop();
}  
int main() {
    string s;
    s="1+4";
    int result = evaluateinfix(s);
    cout << "Result: " << result << endl;

    return 0;
}
