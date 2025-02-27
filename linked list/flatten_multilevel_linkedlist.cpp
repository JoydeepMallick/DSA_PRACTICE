/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */



 Node* mergesortedLL(Node* t1, Node* t2){
	Node *dummyHead = new Node(-1);
	Node *tmp = dummyHead;
	while(t1 != nullptr && t2 != nullptr){
		if(t1->data < t2->data){
			tmp->child = t1;
			t1 = t1->child;
		}else{
			tmp->child = t2;
			t2 = t2->child;
		}
		tmp = tmp->child;
		tmp->next = nullptr;
	}
	if(t1 != nullptr) tmp->child = t1;
	else tmp->child = t2;
	tmp->child->next = nullptr;
	//Node* newhead = dummyHead->child;
	//if(newhead != nullptr)newhead->next = nullptr;



	return dummyHead->child;
}


 //recursive 
Node* flattenLinkedList(Node* head) 
{
	if(head == nullptr || head->next == nullptr) return head;
	
	Node *mergedhead = flattenLinkedList(head->next);
	
	return mergesortedLL(head, mergedhead);
		
}
 

//iterative, note the merge list function is intact
Node* flattenLinkedList(Node* head) 
{
	if(head == nullptr || head->next == nullptr) return head;

	//guranteed at this point that at least 2 nodes present
	Node *t1 = head, *t2 = head->next, *t3 = head->next->next;//t3 is basically the third element
	while(t2 != nullptr){
		t1 = mergesortedLL(t1, t2);
		t2 = t3;
		if(t3 != nullptr) t3 = t3->next;
	}

	return t1;
		
}
