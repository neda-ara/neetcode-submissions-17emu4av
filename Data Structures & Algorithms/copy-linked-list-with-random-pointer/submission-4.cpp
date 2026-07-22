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

        unordered_map<Node*,Node*> mpp;
        mpp[nullptr] = nullptr;

        Node* curr = head;
        while(curr) {
            if(!mpp.count(curr)) {
                mpp[curr] = new Node(0);
            }
            mpp[curr] -> val = curr -> val;

            if(!mpp.count(curr->next)) {
                mpp[curr -> next] = new Node(0);
            }
            mpp[curr] -> next = mpp[curr -> next];

            if(!mpp.count(curr -> random)) {
                mpp[curr -> random] = new Node(0);
            }
            mpp[curr] -> random = mpp[curr -> random];
            curr = curr -> next;
        }
        return mpp[head];
    }
};
