/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* after = node->next;
        int temp = node->val;
        node->val = after->val;
        after->val = temp;
        node->next = node->next->next;
    }
};
