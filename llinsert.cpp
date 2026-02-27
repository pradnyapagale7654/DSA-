#include<iostream>
#include<vector>
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
    list(){
        head=NULL;
    }
    void insert_beg(int val){
    node*newnode=new node(val);
    if(head==NULL){
       
        head=newnode;
    }
    else{
       newnode->next=head;
       head=newnode;
    }
    }
    void insert_end(int val){
        node*newnode=new node(val);
        if(head==NULL){
            head=newnode;
        }
        node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            
        }
        temp->next=newnode;
    }
    void print(){
        if(head==NULL){
            cout<<"list is empty";
        }
        else{
            node*temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        }
    };
    int main(){
        list s;
        s.insert_beg(30);
         s.insert_beg(300);
          s.insert_beg(90);
          s.print();
          s.insert_end(500);
          s.print();
          return 0;
    }