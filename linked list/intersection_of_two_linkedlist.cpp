
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


//better approach
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int n1 = 0, n2 = 0;
    Node *tmp = firstHead;
    while(tmp != nullptr){n1++; tmp = tmp->next;}
    tmp = secondHead;
    while(tmp != nullptr){n2++; tmp = tmp->next;}
    Node *longerLL, *shorterLL;
    if(n1 > n2) { longerLL = firstHead, shorterLL = secondHead; }
    else { longerLL = secondHead, shorterLL = firstHead; }
    int toskip = abs(n1-n2);
    while(toskip--) longerLL = longerLL->next;

    while(longerLL != shorterLL){
        longerLL = longerLL->next;
        shorterLL = shorterLL->next;
    }
    return longerLL;
}


//optimal approach

Node* findIntersection(Node *headA, Node *headB)
{
        Node *t1 = headA, *t2 = headB;
        while(true){
            if(t1 == t2) return t1;//here the case of both NULL also handled
            if(t1 == nullptr) t1 = headB;
            else t1 = t1->next;
            if(t2 == nullptr) t2 = headA;
            else t2 = t2->next;
        }
}