/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //遍历链表, 求出链表的长度, 并记录尾节点指针
 // 遍历第二次len - k, 然后将k长度的节点插入到head之前
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode *cur = head, *last = NULL;
        ListNode* dummy = new ListNode(0);
        int len = 0;
        while(cur->next != NULL) {
            ++len;
            cur = cur->next;
        }
        last = cur; //记录最后一个节点的位置
        len++;
        cur = head;  //重新遍历整个链表
        int before = len - k % len;  //计算k的大于len时, k = k % len;
        if(before == len) {
            return head;
        }
        while(before-- > 1) {  //找到前before个节点, 最后跳出循环时, 是要翻转链表的前驱节点
            cur = cur->next;
        }
        ListNode* new_list = cur->next;
        cur->next = NULL;
        dummy->next = new_list;
        last->next = head;
        return dummy->next;
    }
};
