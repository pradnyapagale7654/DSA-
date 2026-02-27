#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class list{
    node*head;
    node*tail;
    public:
list(){
    head=tail=NULL;
}
void push_front(int val){
    node*newnode=new node(val);
    if(head==NULL){
        head=tail=newnode;
        return;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void push_back(int val){
    node*newnode=new node(val);
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}
void pop_front(){
    node*temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;

}
void pop_back(){
if(head==NULL){
    return;
}
else{
    node*temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    } 
    temp->next=NULL;
    delete tail;
    tail=temp; 
}
}
void insert(int val,int pos){
    if(pos<0){
        cout<<"error";
        return ;
    }
    if(pos==0){
        push_front(val);
        return ;
    }
    node*temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    node*newnode=new node(val);
    newnode->next=temp->next;
    temp->next=newnode;
}
int search(int key){
   node*temp=head;
   int idx=0;
   while(temp!=NULL){
    if(temp->data==key){
        return idx;
    }
    temp=temp->next;
    idx++;
   }
   return -1;
}
void printll(){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL";
}
};

int main(){
    list ll;
ll.push_front(4);
ll.push_front(5);
ll.push_front(6);
ll.printll();
ll.push_back(9);
ll.printll();
ll.pop_front();
ll.printll();
ll.pop_back();
ll.printll();
ll.insert(11,1);
ll.printll();
ll.search(4);
ll.printll();
    return 0;
}