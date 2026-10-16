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
        int count = 0;

        ListNode* curr = head;
        while(curr) {
            count++;
            curr = curr->next;
        }

        int removeIdx = count - n;
        if(removeIdx == 0) {
            return head->next;
        }

        curr = head;
        for(int i=0; i<count; i++) {
            if(removeIdx == i+1) {
                curr->next = curr->next->next;
                break;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
