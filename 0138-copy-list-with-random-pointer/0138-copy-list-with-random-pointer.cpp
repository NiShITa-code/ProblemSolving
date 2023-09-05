/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter = head;
        Node* front = head;
        // first: add copy nodes
        while (iter != NULL) {
            front = iter -> next;
            Node* copy = new Node(iter -> val);
            iter -> next = copy;
            copy -> next = front;
            iter = front;
        }
        // second : make random connections
        iter = head;
        while(iter != NULL) {
            if (iter -> random != NULL) {
                iter -> next -> random = iter -> random -> next;
            }
            iter = iter -> next -> next;
        }
        // third : seprate list by making next conn
        iter = head;
        front = head;
        Node* secHead = new Node(0);
        Node* copy = secHead;
        while (iter != NULL) {
            front = iter -> next -> next;
            copy -> next = iter -> next;
            iter -> next = front;
            iter = front;
            copy = copy -> next;
        }
        return secHead -> next;
    }
};