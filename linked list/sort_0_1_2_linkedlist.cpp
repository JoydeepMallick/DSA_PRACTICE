
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


Node* sortList(Node *head){
    Node *dummy0 = new Node(-1), *dummy0head = dummy0;
    Node *dummy1 = new Node(-1), *dummy1head = dummy1;
    Node *dummy2 = new Node(-1), *dummy2head = dummy2;
    Node *tmp = head;
    while(tmp != nullptr){
        int val = tmp->data;
        if(val == 0) {
            dummy0->next = new Node(val);
            dummy0 = dummy0->next;
        }else if(val == 1) {
            dummy1->next = new Node(val);
            dummy1 = dummy1->next;
        }else{
            dummy2->next = new Node(val);
            dummy2 = dummy2->next;
        }
        tmp = tmp->next;
    }
    //link all nodes
    Node *newhead = dummy0head->next;
    // handle cases like 0011222 and 0002222
    dummy0->next = (dummy1head->next) ? dummy1head->next : dummy2head->next;
    dummy1->next = dummy2head->next;
    dummy2->next = nullptr;
    //clean memory of dummies
    dummy0head->next = nullptr;
    delete dummy0head;
    dummy1head->next = nullptr;
    delete dummy1head;
    dummy2head->next = nullptr;
    delete dummy2head;

    return newhead;
}