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

        int len = nodes.size();
        int idxToRemove = len - n;

        if(idxToRemove == 0) {
            return head -> next;
        }

        nodes[idxToRemove - 1] -> next = idxToRemove == len-1 ? nullptr : nodes[idxToRemove+1];
        return head;
    }
};
