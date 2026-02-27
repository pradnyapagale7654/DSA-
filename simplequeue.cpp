#include<iostream>
using namespace std;
#define size 4
class queue{
    public:
    int arr[size];
    int front;
    int rear;
    queue(){
    front=rear=-1;
    }
    void enqueue(int val){
        if(rear==size-1){
            cout<<"queue is full";
        }
        else{
            if(front==-1){
                front=0;
            }
            rear++;
            arr[rear]=val;
        }
    }
    void dequeue(){
        if(front==-1){
            cout<<"q is empty";
        }
        else{
            int val=arr[front];
            cout<<"deleted element is:"<<val<<endl;;
            front++;
        }
    }
    void display(){
        if(front==-1){
            cout<<"queue is empty";
        }
        else{
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<endl;
            }
        }
    }
};
int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}