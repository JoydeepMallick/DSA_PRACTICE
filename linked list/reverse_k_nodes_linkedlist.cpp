/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

 Node* reverse(Node *head){
    Node* tmp = head;
    Node *prevnode = nullptr;
    while(tmp != nullptr){
        Node *nextnode = tmp->next;
        tmp->next = prevnode;
        prevnode = tmp;
        tmp = nextnode;
    }
    return prevnode;
}

Node* kReverse(Node* head, int k) {
    Node* curstart = head, *lastnewtail = nullptr, *finalhead = nullptr;
    while(curstart != nullptr){
        //find kth node
        Node* kthnode = curstart;
        int cnt = 0;
        while(kthnode != nullptr){
            cnt++;
            if(cnt == k) break;
            kthnode = kthnode->next;
        }

        //store the pointer to next segment if exists
        Node* nextstart = (kthnode != nullptr)? kthnode->next : nullptr;
        Node* newhead;

        if(cnt < k){
            //kth node is invalid for this case
            //no reversal needed
            newhead = curstart;
            if(lastnewtail != nullptr) lastnewtail->next = curstart;
        }else{
            //disconnect k sized LL before reversal
            kthnode->next = nullptr;
            newhead = reverse(curstart);
            //connect previous segment if exists(for first segment its not) to current
            if(lastnewtail != nullptr) lastnewtail->next = newhead;
            //update lastnewtail
            lastnewtail = curstart;
        }

        //just runs once sole purpose to find final head in final answer
        if(curstart == head) finalhead = newhead;
        curstart = nextstart;
    }

    return finalhead;
}