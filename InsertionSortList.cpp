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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* vhead = new ListNode(0);  //设置一个虚拟的头节点简化头部操作
        while(head) {
            ListNode *cur = head;
            ListNode *v = vhead;
            head = head->next;  // head后移
            while(v->next != NULL && v->next->val <= cur->val) { //每次从头找到应该插入位置的前驱
                v = v->next;
            }
            cur->next = v->next;
            v->next = cur;
        }
        head = vhead->next;
        delete vhead;
        return head;
    }
};
