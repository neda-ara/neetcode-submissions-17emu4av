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
        vector<int> merged;

        for(ListNode* head : lists) {
            ListNode* curr = head;
            while(curr) {
                merged.push_back(curr->val);
                curr = curr->next;
            }
        }

        sort(merged.begin(),merged.end());

        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        for(int i=0; i<merged.size(); i++) {
            curr -> next = new ListNode(merged[i]);
            curr = curr->next;
        }
        
        return res->next;
    }
};
