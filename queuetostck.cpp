#include<iostream>
#include<queue>
using namespace std;
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
       q1.push(x); 
    }
    
    int pop() {
       while(q1.size()>1){
        q2.push(q1.front());
        q1.pop();
       }
       // last element is top
       int ans=q1.front();
       q1.pop();
       while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
       } 
       return ans;
    }
    
    int top() {
            while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Last element is the top
        int ans = q1.front();

        // Put it back because top() should NOT remove it
        q2.push(q1.front());
        q1.pop();

        // Restore q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return ans;
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << "Top element: " << stack.top() << endl; // Output: 2
    cout << "Popped element: " << stack.pop() << endl; // Output: 2
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: No
    return 0;
}