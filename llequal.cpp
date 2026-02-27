//checking wheather the linked lists are equal
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode*t1=head1;
    SinglyLinkedListNode*t2=head2;
    if(head1==NULL&&head2==NULL){
        return true;
    }
    if (head1 == NULL || head2 == NULL) {
    return false;}
    while(t1!=NULL && t2!=NULL){
        if(t1->data!=t2->data){
            return false;
        }
        else{
            t1=t1->next;
            t2=t2->next;
        }
    }
    if(t1==NULL && t2==NULL){
        return true;
    }
    else{
    return false;
    }
    }