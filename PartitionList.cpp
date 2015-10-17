// 使左半边的值都小于x, 右半边的值都大于等于x
// 构建两个哑节点, 一个存放小于x, 一个存放大于等于x的. 最后进行拼接
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* cur = head;
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0); //用于插入大于等于x的新链表
        ListNode* d1 = dummy1;
        ListNode* d2 = dummy2;
        while(cur) {
            if(cur->val < x) {
                d1->next = cur;
                d1 = d1->next;
            } else {
                d2->next = cur;
                d2 = d2->next;
            }
            cur = cur->next;
        }
        d2->next = NULL;  //一定要有一个结尾
        d1->next = dummy2->next; //尾部拼接到头部
        head = dummy1->next;
        delete dummy1;  //释放两个哑节点
        delete dummy2;
        return head;
    }
};
