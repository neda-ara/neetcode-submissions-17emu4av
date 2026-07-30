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
        int len = 0;
        ListNode* curr = head;

        while(curr) {
            len++;
            curr = curr -> next;
        }

        int idxToRemove = len - n;

        if(idxToRemove == 0) {
            return head -> next;
        }

        curr = head;

        for(int i=0; i<len; i++) {
            if(i == idxToRemove - 1) {
                curr -> next = curr -> next -> next;
                break;
            }
            curr = curr -> next;
        }
        return head;
    }
};
