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

        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while(true) {
            ListNode* kth = getKth(groupPrev,k);
            if(!kth) {
                break;
            }

            ListNode* groupNext = kth->next;

            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;
            while(curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            ListNode* tmp = groupPrev->next;
            groupPrev->next = prev;
            groupPrev = tmp;
        }

        return dummy.next;
    }

    ListNode* getKth(ListNode* node, int k) {
        while(node && k > 0) {
            k--;
            node = node->next;
        }
        return node;
    }
};
