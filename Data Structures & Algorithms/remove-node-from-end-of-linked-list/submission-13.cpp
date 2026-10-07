/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;

        ListNode* curr = head;
        while(curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        if(n == nodes.size()) {
            return head->next;
        }

        int removeIdx = nodes.size() - n;
        nodes[removeIdx-1]->next = nodes[removeIdx]->next;

        return head;
    }
};
