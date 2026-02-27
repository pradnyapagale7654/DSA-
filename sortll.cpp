#include<iostream>
using namespace std;
class solution{
    public:
    node*midelement(node*head){
        node*slow=head;
        node*fast=head->next; // for managing the odd nodes
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    node*merge(node*left,node*right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        node*dummy=new node(-1);
        node*temp=dummy;
        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        // if one ll becomes empty then 
        while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        return dummy->next;
    }
    node*mergesort(node*head){
        if(head==NULL ||head->next==NULL){
            return head;
        }
        //find the mid
        node*mid=midelement(head);
        // break the ll from mid
        node*left=head;
        node*right=mid->next;
        mid->next=NULL;
        // again break the ll until head==null 
        left=mergesort(left);
        right=mergesort(right);
        // merge the two ll
        node*result=merge(left,right);
        return result;
    }
};

//or 

class Solution{
    public:
    ListNode*midelement(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next; // for managing the odd nodes
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode*merge(ListNode*left,ListNode*right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        if(left->val<right->val){
            left->next=merge(left->next,right);
            return left;
        }
        else{
            right->next=merge(left,right->next);
            return right;
        }
        
    }
    ListNode*sortList(ListNode*head){
        if(head==NULL ||head->next==NULL){
            return head;
        }
        //find the mid
        ListNode*mid=midelement(head);
        // break the ll from mid
        ListNode*left=head;
        ListNode*right=mid->next;
        mid->next=NULL;
        // again break the ll until head==null 
        left=sortList(left);
        right=sortList(right);
        // merge the two ll
        ListNode*result=merge(left,right);
        return result;
    }
};