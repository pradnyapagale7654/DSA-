#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(){
        data=0;
        next=NULL;
    }
    node(int val){
        data=val;
        next=NULL;
    }
};
class list{
    public:
    node*head;
    node*tail;
    list(){
        head=tail=NULL;
    }
    void insert_end(int val){
        node*nn=new node(val);
        if(head==NULL){
            head=tail=nn;
        }
        else{
           tail->next=nn;
           nn->next=NULL;
           tail=nn;
        }
    }
    node* middle(){
        if(head==NULL){
            return NULL;
        }
        node*slow=head;
        node*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
         return slow;
    }
    void print(){
        if(head==NULL){
            cout<<"ll is empty";
        }
        else{
            node*temp=head;
            while(temp->next!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data<<" ";
        }
    }
};
int main(){
    list l;
    l.insert_end(7);
    l.insert_end(6);
    l.insert_end(5);
    l.insert_end(4);
    l.insert_end(3);
    l.print();
    node*mid=l.middle();
    if(mid!=NULL){
        cout<<"mid is:"<<mid->data;
    }
    return 0;
}