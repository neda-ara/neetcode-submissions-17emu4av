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
        vector<int> nodeVals;

        for(ListNode* head : lists) {
            while(head) {
                nodeVals.push_back(head->val);
                head = head->next;
            }
        }

        sort(nodeVals.begin(), nodeVals.end());

        ListNode dummy(0);
        ListNode* curr = &dummy;

        for(int& val : nodeVals) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return dummy.next;
    }
};
