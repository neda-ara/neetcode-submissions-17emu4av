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

        unordered_map<Node*,Node*> otc;
        Node* curr = head;
        while(curr) {
            otc[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr) {
            otc[curr]->next = otc[curr->next];
            otc[curr]->random = otc[curr->random];
            curr = curr->next;
        }
        return otc[head];
    }
};
