Node* delAllOcurrence(Node* head){
    Node* tmp = head;
    while(tmp != nullptr){
        if(tmp->data == k){
            if(tmp == head){
                head = head->next;
            }
            Node* nextnode = tmp->next, *prevnode = tmp->prev;
            if(nextnode != nullptr){
                nextnode->prev = prevnode;
            }
            if(prevnode != nullptr){
                prevnode->next = nextnode;
            }
            delete tmp;
            tmp = nextnode;
        }else{
            tmp = tmp->next;
        }
    }
    return head;
}