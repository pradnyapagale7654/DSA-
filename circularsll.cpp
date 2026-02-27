#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
        data=0;
        next=NULL;
    }
    node(int val){
        data=val;
        next=NULL;
    }
};
class circular{
    public:
    node*head;
    node*tail;
    circular(){
        head=NULL;
    }
   void insert_beg(int val){
    node*nn=new node(val);
    if(head==NULL){
        head=tail=nn;
        head->next=head;
    }
    else{
        nn->next=head;
        tail->next=nn;
        head=nn;
    }
   }
   void insert_end(int val){
    node*nn=new node(val);
    if(head==NULL){
        head=tail=nn;
        head->next=head;
    }
    else{
        tail->next=nn;
        nn->next=head;
        tail=nn;
    }
   }
   void insert_pos(int val,int pos){
    node*nn=new node(val);
    if(head==NULL){
        head=tail=nn;
        head->next=head;
    }
    else{
        node*t=head;
        for(int i=1;i<pos-1 && t!=head;i++){
            t=t->next;
        }
        nn->next=t->next;
        t->next=nn;

    }
   }
   void search(int key){
    if(head==NULL){
        cout<<"ll is empty";
    }
    else{
        node*t=head;
        int pos=1;
        int flag=0;
        while(t->next!=head){
            if(t->data==key){
                cout<<"found :"<<pos<<endl;
                pos++;
                flag=1;
                break;
            }
            else{
                t=t->next;
                pos++;
            }
        }
        if(flag==0){
            cout<<"not found";
        }
    }
   }
   void delete_beg(){
    if(head==NULL){
        cout<<"empty";
    }
    else if(head==tail){
        delete head;
        head=tail=NULL;
    }
    else{
        node*temp=head;
        head=head->next;
        tail->next=head;
        temp->next=NULL;
        delete temp;
    }
   }
   void delete_end(){
    if(head==NULL){
        cout<<"ll is empty";
    }
    else if(head==tail){
        delete head;
        head=tail=NULL;
    }
    else{
        node*temp=tail;
        node*prev=head;
        while(prev->next!=tail){
            prev=prev->next;
        }
        tail=prev;
        tail->next=head;
        temp->next=NULL;
        delete temp;
    }
   }
    void print(){
        if(head==NULL){
            cout<<"ll is empty";
        }
        else{
            node*temp=head;
            while(temp->next!=head){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data<<" ";
        }
    }
};
int main(){
    circular l;
   l.insert_beg(3);
   l.insert_beg(1);
   l.insert_end(7);
   l.insert_pos(66,2);
   l.search(1);
   l.delete_beg();
   l.delete_end();
    l.print();
    return 0;
}
