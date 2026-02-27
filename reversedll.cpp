#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;
    node(){
        data=0;
        next=prev=NULL;
    }
    node(int val){
        data=val;
        next=prev=NULL;
    }
};
class ll{
    public:
    node*head;
    node*tail;
    ll(){
        head=tail=NULL;
    }
    void insert(int val){
        node*nn=new node(val);
        if(head==NULL){
            head=tail=nn;
        }
        else{
            nn->next=head;
            head->prev=nn;
            head=nn;
        }
    }
    void reverse(){
        if (head==NULL){
            cout<<"list is empty";
        }
        else{
            node*curr=head;
            node*temp=NULL;
            while(curr!=NULL){
                temp=curr->prev;
                curr->prev=curr->next;// swapping the next and previous node with each other
                curr->next=temp;
                curr=curr->prev;
            }
          if(temp!=NULL){
            head=temp->prev;//new node 
          }
        }
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
    ll l;
    l.insert(3);
    l.insert(4);
    l.insert(6);
    l.insert(7);
    l.print();
    l.reverse();
    l.print();
    return 0;
}
