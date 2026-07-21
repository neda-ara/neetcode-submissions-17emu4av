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

        unordered_map<Node*,Node*> orgToCopy;
        Node* curr = head;

        while(curr) {
            Node* copy = new Node(curr -> val);
            orgToCopy[curr] = copy;
            curr = curr -> next;
        }

        curr = head;
        while(curr) {
            Node* copy = orgToCopy[curr];
            copy -> next = orgToCopy[curr -> next];
            copy -> random = orgToCopy[curr -> random];
            curr = curr -> next;
        }

        return orgToCopy[head];
    }
};
