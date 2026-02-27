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
    node*addnum(node*head1,node*head2){
        node*t1=head1;
        node*t2=head2;
        node*dummy=new node(-1);
        node*curr=dummy;
        int carry=0;
        while(t1!=NULL || t2!=NULL){
            int sum=carry;
            if(t1){
                sum=sum+t1->data;
            }
            if(t2){
                sum=sum+t2->data;
            }
            node*nn=new node(sum%10);//we have to add the sum but in reverse order
            carry=sum/10; //to find that wheather carry is present in sum or not if yes then find it
            curr->next=nn;
            curr=curr->next;
            if(t1){
                t1=t1->next;
            }
            if(t2){
                t2=t2->next;
            }
        }
        if(carry){
            node*nn=new node(carry);
            curr->next=nn;
        }
        return dummy->next;  // new head
    }
    void print(){
        if(head==NULL){
            cout<<"ll is empty";
        }
        else{
            node*temp=head;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }
};
int main(){
    list l1,l2;
    l1.insert_beg(4);
    l1.insert_beg(1);
    l1.insert_beg(2);
    l1.insert_beg(3);
    l1.insert_beg(4);
    cout<<"1st ll is:"<<" ";
    l1.print();
    l2.insert_beg(4);
    l2.insert_beg(1);
    l2.insert_beg(2);
    l2.insert_beg(3);
    l2.insert_beg(4);
    cout<<"2nd ll is:"<<" ";
    l2.print();
    node*result=l1.addnum(l1.head,l2.head);
    cout << "Resultant sum list: ";
    node* temp = result;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}