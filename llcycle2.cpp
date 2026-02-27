#include<iostream>
using namespace std;
class solution{
    public:
    node*detectcycle(node*head){
        node*slow=head;
        node*fast=head;
        if(head==NULL){
            cout<<" ll is empty";
        }
        else{
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast){
                    fast=head;
                    while(fast!=slow){
                      fast=fast->next;
                      slow=slow->next;
                    } 
                return slow;              }
            }
        }
        return 0;
    }
};