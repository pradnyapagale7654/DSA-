#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node*prev;
    node*next;
    node(int val){
        data=val;
        prev=next=NULL;
    }
};
class list{
    public:
    node*head;
    node*tail;
    list(){
        head=tail=NULL;
    }
    void push_front(int val){
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
    void push_back(int val){
        node* nn=new node(val);
        if(head==NULL){
            head=tail=NULL;
        }
        else{
            nn->prev=tail;
            tail->next=nn;
            tail=nn;
        }
    }
    void delete_front(){
        if(head==NULL){
            cout<<"empty";
        }
           node*temp=head;
            head=head->next;
            if(head!=NULL){
            head->prev=NULL;
            }
            temp->next=NULL;
            delete temp;
    }
    void delete_back(){
        if(head==NULL){
            cout<<"empty";
        }
        node*temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
    }
    void print(){
        if(head==NULL){
            cout<<"ll is empty";
        }
        else{
            node*temp=head;
            while(temp->next!=NULL){
                cout<<temp->data;
                temp=temp->next;
            }
            cout<<temp->data;
        }
    }
   
};
int main(){
    list l;
    l.push_front(5);
    l.push_front(3);
    l.push_front(7);
    l.push_back(9);
    l.print();
    l.delete_front();
    l.delete_back();
    l.print();
    return 0;
}