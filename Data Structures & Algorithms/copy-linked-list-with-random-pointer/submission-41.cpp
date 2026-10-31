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
        otc[nullptr] = nullptr;

        Node* curr = head;
        while(curr) {
            if(!otc.count(curr)) {
                otc[curr] = new Node(0);
            }
            otc[curr]->val = curr->val;

            if(!otc.count(curr->next)) {
                otc[curr->next] = new Node(0);
            }
            otc[curr]->next = otc[curr->next];

            if(!otc.count(curr->random)) {
                otc[curr->random] = new Node(0);
            }
            otc[curr]->random = otc[curr->random];
            curr = curr->next;
        }
        return otc[head];
    }
};
