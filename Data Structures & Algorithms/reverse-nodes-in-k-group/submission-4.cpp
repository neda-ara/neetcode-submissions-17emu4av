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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) {
            return nullptr;
        }

        ListNode* curr = head;
        int count = 0;

        while(curr && count < k) {
            count++;
            curr = curr->next;
        }

        if(count == k) {
            ListNode* nextGroupAhead = reverseKGroup(curr,k);

            ListNode* prev = nextGroupAhead;
            curr = head;

            for(int i=0; i<k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            return prev;
        }

        return head;
    }
};
