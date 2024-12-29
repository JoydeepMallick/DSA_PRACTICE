template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(T data, T* next)
    {
        this->data = data;
        this->next = next;
    }
};

int searchInLinkedList(Node<int> *head, int k) {
    Node<int> *tmp = head;
    while(tmp){
        if(tmp->data == k) return 1;
        tmp = tmp->next;
    }
    return 0;
}