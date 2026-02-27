#include<iostream>
using namespace std;
#define size 4
class Cqueue{
    public:
    int arr[size];
    int front;
    int rear;
    Cqueue(){
    front=rear=-1;
    }
    void enqueue(int val){
        if(rear==size-1 && front==0){
            cout<<"queue is full";
        }
        if(front==-1){
            front=0;
        }
            rear=(rear+1)%size;
            arr[rear]=val;
        cout<<"val is inserted:"<<val<<endl;
    }
    void dequeue(){
        if(rear==-1){
            cout<<"q is empty";
        }
        else{
            int val=arr[front];
            cout<<"deleted element is:"<<val<<endl;;
            front=(front+1)%size;
        }
    }
    void display(){
        if(front==-1){
            cout<<"queue is empty";
        }
        else{
            int i=front;
            while(true){
                cout<<arr[i]<<endl;
                if(i==rear){
                    break;
                    }
                    i=(i+1)%size;
            }
        }
    }
};
int main(){
    Cqueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(50);
    q.display();
    return 0;
}