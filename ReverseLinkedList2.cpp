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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        n = n - m + 1;
        ListNode* cur = dummy;
        ListNode *pre = NULL, *end = NULL, *front = NULL;
        while(m-- > 1) {
            cur = cur->next;  //保存要翻转的前一个节点
        }
        pre = cur; 
        end = cur->next; //end指向的节点, 翻转后为最后一个节点
        while(n-- > 0) {
            cur = pre->next;
            pre->next = cur->next;  
            cur->next = front;  //将翻转的这段节点拿出来拼接, 最后在接回去
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        end->next = cur;
        return dummy->next;
    }
};
