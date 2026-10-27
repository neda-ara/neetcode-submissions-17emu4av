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
        int count = 0;
        ListNode* curr = head;

        while(curr && count < k) {
            count++;
            curr = curr->next;
        }

        if(count == k) {
            ListNode* nextGroupAhead = reverseKGroup(curr,k);
            
            for(int i=0; i<k; i++) {
                ListNode* next = head->next;
                head->next = nextGroupAhead;
                nextGroupAhead = head;
                head = next;
            }

            return nextGroupAhead;
        }

        return head;
    }
};
