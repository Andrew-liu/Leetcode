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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k < 2) {  //这种情况无需翻转
            return head;
        }
        ListNode* dummy = new ListNode(0); //构造一个哑节点
        dummy->next = head;
        ListNode* p = dummy;
        while(p->next && p->next->next) { //注意条件
            ListNode *prev = p->next, *cur = prev->next;  //注意第一个节点无需翻转, 只需要将第二个节点插入到第一个之前
            int i = 0; //计算器
            while(cur && i < k - 1) {
                ListNode *temp = cur->next; //记录cur之后的位置
                cur->next = prev;
                prev = cur;
                cur = temp;
                i++;
            }
            if(i == k -1) { //翻转k个节点结束
                ListNode* temp = p->next;
                p->next->next = cur;
                p->next = prev;
                p = temp;
            } else {
                cur = prev->next;
                prev->next = NULL;
                while(cur != p->next) {
                    ListNode* temp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = temp;
                }
                break;
            }
        }
        return dummy->next;
    }
};
