#include<iostream>
using namespace std;
#define size 4
class pqueue{   // priority queue can be implemented either insertion according to priority or deletion according to priority
    public:    // deletion according to priority
    int front;
    int rear;
    int data[4];
    int priority[4];
    int n;
    pqueue(){
    front=rear=-1;
    n=0;
    }
  void enqueue(int d,int p){
    if(n==size){
        cout<<"q is full";
    }
    else{
        data[n]=d;
        priority[n]=p;
        n++;
    }
  }
   void display(){
    if(n==0){
        cout<<"q is empty";
    }
    else{
        for(int i=0;i<n;i++){
            cout<<data[i]<<" "<<priority[i]<<endl;
        }
    }
   }
   void deletionp(){
    if(n==0){
        cout<<"q is empty";
    }
    int index=gethighestindex();
    cout<<"deleted element is:"<<" "<<data[index]<<" "<<priority[index]<<endl;
    // shifting the elements
    for(int i=1;i<n;i++){
    data[i]=data[i+1];
    priority[i]=priority[i+1];
   }
   n--;
}
   int gethighestindex(){
    int highindex=0;
    for(int i=1; i<n; i++){
        if(priority[i] > priority[highindex]){
            highindex = i;
        }
    }
    
    return highindex;
   }
};
int main(){
    pqueue q;
    q.enqueue(10,3);
    q.enqueue(60,1);
    q.enqueue(17,7);
    q.enqueue(69,9);
    q.display();
    q.deletionp();
    q.display();
    return 0;
}