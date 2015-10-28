/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 就地执行, 不能改变节点的值
 //暴力方法会超时, 简单的方法是, 找到中间节点, 然后翻转后办个单链表, 然后逐个插入前半个单链表
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head; //使用快慢指针找到中间节点
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next; //second指向后半段链表
        slow->next = NULL; //从中间断开两个链表
        ListNode *cur = second;
        ListNode* pre = NULL;
        while(cur != NULL) {  //翻转链表
            ListNode* end = cur->next;
            cur->next = pre;
            pre = cur;
            cur = end;
        }
        while(head && pre) {  //分别从头开始遍历两个链表
            ListNode* end = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = end;
            head = end;
        }
    }
};
