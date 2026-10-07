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

        if(n == count) {
            return head->next;
        }

        int removeIdx = count - n;
        curr = head;
        
        for(int i=0; i<count-1;i++) {
            if(i+1 == removeIdx) {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }

        return head;
    }
};
