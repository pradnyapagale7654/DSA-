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
    list(){
        head=NULL;
    }
    void insert_beg(int val){
        node*nn=new node(val);
        if(head==NULL){
            head=nn;
        }
        else{
            nn->next=head;
            head=nn;
        }
    }
    void delete_middle(){
        if(head==NULL){
            cout<<"ll is empty";
        }
        else{
            node*prev=NULL;
            node*slow=head;
            node*fast=head;
            while(fast!=NULL && fast->next!=NULL){
                prev=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
            prev->next=slow->next;
            delete slow;
        }
    }
    void print(){
        if(head==NULL){
            cout<<"ll is empty";
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
    list l;
    l.insert_beg(1);
    l.insert_beg(2);
    l.insert_beg(3);
    l.insert_beg(4);
    l.insert_beg(5);
    l.delete_middle();
    l.print();
    return 0;
}