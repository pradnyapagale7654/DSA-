#include<iostream>
using namespace std;
class node {

    public:
    
        int coeff;
    
        int pow;
    
        node* next;
    
    
        node() {
    
            coeff=0;
    
            pow=0;
    
            next = NULL;
    
        }
    
        node(int c,int p){
    
            coeff=c;
    
            pow=p;
    
            next=NULL;
    
    
        }
    
    };
    
    
    class ll {
    
    public:
    
        node* head;
    
        ll() {
    
            head = NULL;
    
        }
    
    
        void create_node(int c,int p) {
    
            node*nn=new node(c,p);
    
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
    
    
        void print(){
    
           if(head==NULL){
    
            cout<<"ll is empty";
    
            }
    
    
            else{
    
                node*temp=head;
    
                  while(temp!=NULL){
    
                    cout<<temp->coeff<<"x^"<<temp->pow<<" + ";
    
                  temp=temp->next; 
    
                
    
            }
    
        }
    
    }
    
    
    
    void poly_add(ll &l1, ll &l2) {
    
        node* p1 = l1.head;
    
        node* p2 = l2.head;
    
        node*curr=  NULL;
    
    
        while (p1 != NULL && p2 != NULL) {
    
            node* p3 = new node();
    
            if (p1->pow > p2->pow) {
    
                p3->coeff = p1->coeff;
    
                p3->pow = p1->pow;
    
                p1 = p1->next;
    
    
            } 
    
    
            else if (p2->pow > p1->pow) {
    
                p3->coeff = p2->coeff;
    
                p3->pow = p2->pow;
    
                p2 = p2->next;
    
            } 
    
    
            else { 
    
                p3->coeff = p1->coeff + p2->coeff;
    
                p3->pow = p1->pow;
    
                p1 = p1->next;
    
                p2 = p2->next;
    
            }
    
            
    
              p3->next = NULL;
    
    
         if (head == NULL) {
    
              head = p3;    
    
              curr = p3;    
    
            
    
        }
    
        else {
    
            curr->next = p3; 
    
            curr=p3;
    
        }
    
        }
    
    
    
            while (p1 != NULL) {
    
                node* nn = new node(p1->coeff, p1->pow);
    
                if (head == NULL) {
    
                    head = nn;
    
                     curr=nn;
    
                } else {
    
                    curr->next = nn;
    
                    curr = nn;
    
                }
    
                p1 = p1->next;
    
            }
    
    
          
    
            while (p2 != NULL) {
    
                node* nn = new node(p2->coeff, p2->pow);
    
                if (head == NULL) {
    
                    head = nn;
    
                    curr = nn;
    
                } else {
    
                    curr->next = nn;
    
                    curr = nn;
    
                }
    
                p2 = p2->next;
    
            }
    
        }
    
            
    
    
    };
    
    
    
        int main(){
    
            ll l1,l2,l3;
    
            int n1;
    
            cout<<"Enter the number of  nodes in the polynomial 1:";
    
            cin>>n1;
    
    
            int c,p;
    
            for(int i=0;i<n1;i++){
    
                cout<<"Enter the node "<<i+1<<":";
    
                cin>>c>>p;
    
                l1.create_node(c,p);
    
            }
    
            cout<<"POLYNOMIAL 1:"<<endl;
    
            l1.print();
    
            cout<<"\n\n";
    
    
    
           cout<<"-----------------------------------"<< endl;
    
    
    
            int n2;
    
            cout<<"Enter the number of nodes  in the polynomial 2:";
    
            cin>>n2;
    
    
    
            for(int i=0;i<n2;i++){
    
             cout<<"Enter the node "<<i+1<<":";
    
             cin>>c>>p;
    
             l2.create_node(c,p);
    
            }
    
    
            cout<<"POLYNOMIAL 2:" << endl;
    
            l2.print();
    
            cout<<"\n\n";
    
    
    
            l3.poly_add(l1,l2);
    
            cout<<"SUM of the two polynomials:"<<endl;
    
            l3.print();
    
            return 0;
    
        }