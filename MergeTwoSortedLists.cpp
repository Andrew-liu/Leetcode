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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        // 找到节点值较小的一个作为合并后的头结点
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* tail = head; //指向新链表的尾节点
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if(l1 != NULL) {  //如果l1有剩余, 直接练到尾部
            tail->next = l1;
        }  
        if (l2 != NULL) { // 通过l2有剩余, 直接链到尾部
            tail->next = l2;
        }
        return head;
    }
}; 

// 使用哑节点的方案判断更加简单
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if(l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* dummy = new ListNode(0);  // 哑节点作为新的链表的头结点
        ListNode* cur = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 != NULL) {
            cur->next = l1;
        }
        if(l2 != NULL) {
            cur->next = l2;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
