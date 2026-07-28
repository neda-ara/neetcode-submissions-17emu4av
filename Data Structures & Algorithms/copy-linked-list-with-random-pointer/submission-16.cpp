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
        if(!head) return nullptr;

        Node* l1 = head;
        while(l1) {
            Node* l2 = new Node(l1->val);
            l2 -> next = l1 -> next;
            l1 -> next = l2;
            l1 = l2 -> next;
        }

        l1 = head;
        while(l1) {
            Node* l2 = l1 -> next;
            l2 -> random = l1 -> random ? l1 -> random -> next : nullptr;
            l1 = l2 -> next;
        }

        l1 = head;
        Node* newHead = head -> next;
        while(l1) {
            Node* l2 = l1 -> next;
            l1 -> next = l2 -> next;
            l2 -> next = l1 -> next ? l1 -> next -> next : nullptr;
            l1 = l1 -> next;
        }

        return newHead;
    }
};
