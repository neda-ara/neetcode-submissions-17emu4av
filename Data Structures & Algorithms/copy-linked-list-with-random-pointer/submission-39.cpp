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
    unordered_map<Node*,Node*> otc;
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return nullptr;
        }

        if(otc.count(head)) {
            return otc[head];
        }

        Node* copy = new Node(head->val);
        otc[head] = copy;
        otc[head]->next = copyRandomList(head->next);
        otc[head]->random = otc[head->random];
        return copy;
    }
};
