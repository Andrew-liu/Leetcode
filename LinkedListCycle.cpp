/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 经典问题, 快慢指针的解法
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return false;
        }
        ListNode* quick = head;
        ListNode* slow = head;
        while(quick != NULL && quick->next != NULL) {
            quick = quick->next->next;
            slow = slow->next;
            if (quick == slow) {
                return true;
            }
        }
        return false;
    }
};
