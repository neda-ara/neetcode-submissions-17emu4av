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
        unordered_map<Node*,Node*> oldToNew;
        oldToNew[nullptr] = nullptr;

        Node* curr = head;
        while(curr) {
            if(!oldToNew.count(curr)) {
                oldToNew[curr] = new Node(0);
            }
            oldToNew[curr]->val = curr->val;

            if(!oldToNew.count(curr->next)) {
                oldToNew[curr->next] = new Node(0);
            }
            oldToNew[curr]->next = oldToNew[curr->next];

            if(!oldToNew.count(curr->random)) {
                oldToNew[curr->random] = new Node(0);
            }
            oldToNew[curr]->random = oldToNew[curr->random];

            curr = curr->next;
        }

        return oldToNew[head];
    }
};
