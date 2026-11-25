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
        if(lists.empty()) {
            return nullptr;
        }

        vector<int> nodes;

        for(ListNode* head : lists) {
            ListNode* curr = head;
            while(curr) {
                nodes.push_back(curr->val);
                curr = curr->next;
            }
        } 

        sort(nodes.begin(), nodes.end());

        ListNode dummy(0);
        ListNode* curr = &dummy;

        for(int val : nodes) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return dummy.next;
    }
};
