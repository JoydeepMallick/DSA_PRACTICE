class Node {
     public int data;
     public Node next;

     Node()
     {
         this.data = 0;
         this.next = null;
     }

     Node(int data)
     {
         this.data = data;
         this.next = null;
     }

     Node(int data, Node next)
     {
         this.data = data;
         this.next = next;
     }
 };

public class Solution {
    public static Node constructLL(int []arr) {
        Node head = new Node(arr[0]);
        Node mover = head;
        for(int i = 1; i < arr.length; i++){
            Node tmp = new Node(arr[i]);
            mover.next = tmp;
            mover = tmp;
        }
        return head;
    }
}

public static void main(String[] args) {
    int []arr = {1, 2, 3, 4, 5};
    Node head = constructLL(arr);
    while(head != null){
        System.out.print(head.data + " ");
        head = head.next;
    }
}