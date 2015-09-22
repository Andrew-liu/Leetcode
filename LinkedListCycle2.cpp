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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        //找到第一次相遇的地方
        ListNode *cur = head, *pre = head;
        while(cur != NULL && cur->next != NULL) {
            cur =  cur->next->next;
            pre = pre->next;
            if (cur == pre) {
                break;
            }
        } 
        if (cur == NULL || cur->next == NULL) {
            return NULL;
        }
        // 此时必有环
        pre = head;
        while(cur != NULL) {
            if(cur == pre) {
                return cur;
            }
            cur = cur->next;
            pre = pre->next;
            
        }
    }
};
