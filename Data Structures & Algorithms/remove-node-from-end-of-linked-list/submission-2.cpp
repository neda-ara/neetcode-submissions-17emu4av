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
            nodes.emplace_back(curr);
            curr = curr -> next;
        }

        int removeIdx = nodes.size() - n;
        if(removeIdx == 0) {
            return head -> next;
        }

        nodes[removeIdx - 1] -> next = removeIdx == nodes.size() - 1 ? nullptr : nodes[removeIdx+1];
        return head;
    }
};
