#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
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
class list{
    public:
    node*head;
    node*tail;
    list(){
        head=tail=NULL;
    }
    void insert_beg(int val){
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
    void insert_end(int val){
        node*nn =new node(val);
        if(head==NULL){
            head=tail=nn;
        }
        else{
          nn->prev=tail;
          tail->next=nn;
          tail=nn;
        }
    }
    void insert_bet(int val,int pos){
         node*nn=new node(val);
        if(head==NULL){
            head=tail=nn;
        }
        else{
            node*temp=head;
            for(int i=1;i<pos-1 && temp!=NULL;i++){
                temp=temp->next;
            }
            nn->next=temp->next;
            nn->prev=temp;
            if(temp->next!=NULL){
                temp->next->prev=nn;
            }
            temp->next=nn;
             }
    }
    void delete_beg(){
        if(head==NULL){
            cout<<"list is empty";
        }
        else{
            node*temp=head;
            head=temp->next;
            if(head!=NULL){
                head->prev=NULL;
            }
            temp->next=NULL;
            delete temp;
        }
    }
    void delete_end(){
        if(head==NULL){
            cout<<"link list is empty";
        }
        else{
            node*temp=tail;
            tail=temp->prev;
            if(tail!=NULL){
                tail->next=NULL;
            }
            else{
                temp->prev=NULL;
            }
        }
    }
    int search(int key){
        if(head==NULL){
            return -1;
        }
        else{
            node*temp=head;
            int idx=0;
            while(temp!=NULL){
                if(temp->data==key){
                    return idx;
                }
                temp=temp->next;
                idx++;
            }
        }
             return -1;
    }
    void print(){
        if(head==NULL){
            cout<<"ll is empty";
        }
        else{
            node*temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" "<<endl;
                temp=temp->next;
            }
        }
    }
};
int main(){
    list l;
    l.insert_beg(6);
     l.insert_beg(7);
      l.insert_beg(8);
      l.insert_end(1);
      l.insert_end(2);
      l.insert_bet(99,4);
      l.print();
      l.delete_beg();
      l.delete_end();
      l.print();
      cout<<"element is present at index:"<<l.search(99);
      return 0;
}