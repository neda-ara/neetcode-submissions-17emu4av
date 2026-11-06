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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (ListNode* head : lists) {
            if (head) {
                minHeap.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!minHeap.empty()) {
            ListNode* nextMin = minHeap.top();
            minHeap.pop();

            curr->next = nextMin;
            nextMin = nextMin->next;
            if (nextMin) {
                minHeap.push(nextMin);
            }
            curr = curr->next;
        }

        return dummy.next;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return nullptr;
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }

        return dummy.next;
    }
};
