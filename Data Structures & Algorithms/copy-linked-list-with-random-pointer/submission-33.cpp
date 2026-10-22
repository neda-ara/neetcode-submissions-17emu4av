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
    unordered_map<Node*,Node*> orgToCopy;
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return nullptr;
        }
        if(orgToCopy.count(head)) {
            return orgToCopy[head];
        }

        Node* copy = new Node(head->val);
        orgToCopy[head] = copy;
        orgToCopy[head]->next = copyRandomList(head->next);
        orgToCopy[head]->random = orgToCopy[head->random];
        return copy;
    }
};
