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
        if(!head) {
            return nullptr;
        }

        Node* l1 = head;
        while(l1) { // Attach copy nodes to random of original nodes
            Node* copy = new Node(l1->val);
            copy->next = l1->random;
            l1->random = copy;
            l1 = l1->next;
        }

        l1 = head;
        while(l1) { // Fix random pointers of copy nodes
            Node* copy = l1->random;
            copy->random = copy->next ? copy->next->random : nullptr;
            l1 = l1->next;
        }

        l1 = head;
        Node* newHead = l1->random;

        while(l1) { // Separate l1 and l2
            Node* l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : nullptr;
            l1 = l1->next;
        }

        return newHead;
    }
};
