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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* pre = NULL;  //前驱节点
        ListNode* cur = head;  //当前遍历节点
        while(cur != NULL) {
            if (cur->val == val) {
                if (pre == NULL) {  //开头节点
                    head = cur->next;
                    cur= cur->next;
                } else {
                    pre->next = cur->next;
                    cur = cur->next;
                }
            } else{  //指针都后移
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
