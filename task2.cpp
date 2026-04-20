#include<iostream>
#include<stack>
using namespace std;

class Queue{
stack<int> s1, s2;

public:

void enqueue(int x){
    s1.push(x);
    cout<<"Inserted: "<<x<<endl;
}

void dequeue(){

    if(s1.empty() && s2.empty()){
        cout<<"Queue Empty"<<endl;
        return;
    }

    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }

    cout<<"Deleted: "<<s2.top()<<endl;
    s2.pop();
}

void display(){

    stack<int> temp1 = s1;
    stack<int> temp2 = s2;

    if(temp1.empty() && temp2.empty()){
        cout<<"Queue Empty"<<endl;
        return;
    }

    cout<<"Queue: ";

    while(!temp2.empty()){
        cout<<temp2.top()<<" ";
        temp2.pop();
    }

    int arr[100],i=0;

    while(!temp1.empty()){
        arr[i++] = temp1.top();
        temp1.pop();
    }

    for(int j=i-1;j>=0;j--){
        cout<<arr[j]<<" ";
    }

    cout<<endl;
}

};

int main(){

    Queue q;
    int ch,x,n;

    while(1){

        cout<<"\n1.Enqueue";
        cout<<"\n2.Dequeue";
        cout<<"\n3.Display";
        cout<<"\n4.Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch){

        case 1:
            cout<<"Enter number of elements: ";
            cin>>n;

            for(int i=0;i<n;i++){
                cin>>x;
                q.enqueue(x);
            }
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            exit(0);
        }
    }
}