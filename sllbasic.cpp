#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int val=0){
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
        node* nn=new node(val);
        if(head==NULL){
            head=nn;
        }
        else{
            nn->next=head;
            head=nn;
        }
    }
    void insert_end(int val){
        node *nn=new node(val);
        if(head==NULL){
            head=nn;
        }
        else{
            node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
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
          head=head->next;
          temp->next=NULL;
          delete temp;
        }
    }
    void delete_end(){
        if(head==NULL){
            cout<<"list is empty";
        }
        else{
            node*prev=head;
            node*temp=head;
            temp=temp->next;
            while(temp->next!=NULL){
                temp=temp->next;
                prev=prev->next;
            }
            prev->next=NULL;
            delete temp;
        }
    }
    void insert_pos(int pos){
        node *nn=new node(pos);
        if(head==NULL){
          head=nn;  
        }
        else{
            node*temp=head;
            for(int i=1;i<pos-1&& temp->next!=NULL;i++){
               temp=temp->next; 
            }
            nn->next=temp->next;
            temp->next=nn;
        }
    }
    int search(int key){
        if(head==NULL){
            cout<<"list is empty";
            return -1;
        }
        else{
            node*temp=head;
            int idx=0;
            while(temp!=NULL){
                if(temp->data==key){
                return idx;}
                temp=temp->next;
                idx++;
            }
             return -1;
        }
    }
    void print(){
        if(head==NULL){
            cout<<"list is empty";
        }
        else{
            node*temp=head;
            while(temp->next!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
            cout<<temp->data<<" "<<endl;;
        }
    }
    void nextelement(){
        int key;
        cout<<"enter the key element:";
        cin>>key;
        if(head==NULL){
            cout<<"list is empty";
        }
        else{
            node*temp=head;
            node*prev=NULL;
           while( temp!=NULL &&temp->data!=key){
               prev=temp;
             temp=temp->next;  
           }
           cout<<"next:"<<temp->next->data;
           cout<<"prev:"<<prev->data;
        }
    }
};
int main(){
    list l;
    l.insert_beg(3);
    l.insert_end(8);
    l.insert_pos(2);
    l.insert_beg(4);
    l.insert_beg(1);
     l.insert_end(11);
    l.print();
    cout<<l.search(2)<<endl;
    l.nextelement();
   return 0;
}