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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        //只有一个节点
        if (head->next == NULL) {
            return head;
        }
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* end = head->next;
        while(cur->next != NULL) {
            cur->next = pre;
            pre = cur;
            cur = end; 
            end = end->next;
        }
        // 最后一次循环时 cur并没有被翻转, 所以需要最后处理一下cur所指向的节点
        // cur是最后一个节点, 翻转后变成了头结点
        cur->next = pre;
        head = cur;
        return head;
    }
};
// 更加清晰的方法, 不用考虑最后一次循环
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* lst = NULL;
        while(cur) {
            lst = cur->next;
            cur->next = pre;
            pre = cur;
            cur = lst;
        }
        return pre;
    }
};
