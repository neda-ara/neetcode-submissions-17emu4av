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
        unordered_map<Node*,Node*> orgToCopy;
        orgToCopy[nullptr] = nullptr;

        Node* curr = head;
        while(curr) {
            if(!orgToCopy.count(curr)) {
                orgToCopy[curr] = new Node(0);
            }
            orgToCopy[curr] -> val = curr -> val;

            if(!orgToCopy.count(curr -> next)) {
                orgToCopy[curr -> next] = new Node(0);
            }
            orgToCopy[curr] -> next = orgToCopy[curr -> next];

            if(!orgToCopy.count(curr -> random)) {
                orgToCopy[curr -> random] = new Node(0);
            }
            orgToCopy[curr] -> random = orgToCopy[curr -> random];

            curr = curr -> next;
        }
        return orgToCopy[head];
    }
};
