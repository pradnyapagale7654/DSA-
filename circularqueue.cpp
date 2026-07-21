#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;
class MyCircularQueue {
public:
vector<int>q;
int front,rear,size;
int count;
    MyCircularQueue(int k) {
        size=k;
        q.resize(k);
        count=0;
        rear=front=-1;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            front=rear=0;
        }
        else{
        rear=(rear+1)%size;}
        q[rear]=value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if(front==rear){
            //only one el is present
            front=rear=-1;
        }
        else{
        front=(front+1)%size;
        }
        count--;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return q[rear];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
       return count==size;
    }
};
int main() {
    MyCircularQueue obj(3);

    cout << boolalpha;

    cout << "enQueue(1): " << obj.enQueue(1) << endl;
    cout << "enQueue(2): " << obj.enQueue(2) << endl;
    cout << "enQueue(3): " << obj.enQueue(3) << endl;
    cout << "enQueue(4): " << obj.enQueue(4) << endl;

    cout << "Front: " << obj.Front() << endl;
    cout << "Rear: " << obj.Rear() << endl;

    cout << "isFull: " << obj.isFull() << endl;
    cout << "isEmpty: " << obj.isEmpty() << endl;

    cout << "deQueue(): " << obj.deQueue() << endl;

    cout << "Front after deQueue: " << obj.Front() << endl;
    cout << "Rear after deQueue: " << obj.Rear() << endl;

    cout << "enQueue(4): " << obj.enQueue(4) << endl;

    cout << "Front: " << obj.Front() << endl;
    cout << "Rear: " << obj.Rear() << endl;

    return 0;
}