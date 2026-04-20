#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insert(node* &head,int val){
    node* temp = new node(val);

    if(head == NULL){
        head = temp;
        return;
    }

    node* t = head;
    while(t->next != NULL){
        t = t->next;
    }

    t->next = temp;
    temp->prev = t;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

node* reverseAlternateK(node* head,int k){

    if(!head) return NULL;

    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;

    // Reverse first k nodes
    while(current != NULL && count < k){
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
        count++;
    }

    // connect with remaining list
    if(head != NULL)
        head->next = current;

    // Skip next k nodes
    count = 0;
    while(count < k-1 && current != NULL){
        current = current->next;
        count++;
    }

    // recursion
    if(current != NULL)
        current->next = reverseAlternateK(current->next,k);

    return prev;
}

int main(){

    node* head = NULL;
    int n,x,k;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>x;
        insert(head,x);
    }

    cout<<"Enter K: ";
    cin>>k;

    cout<<"Original list: ";
    display(head);

    head = reverseAlternateK(head,k);

    cout<<"\nAfter reverse: ";
    display(head);

    return 0;
}