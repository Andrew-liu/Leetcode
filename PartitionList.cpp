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


// 只需要使用一个新的节点存储小于x的节点, 剩下的保存在原链表中, 使用哑节点记录原链表的起点
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
        if(head == NULL) {
            return NULL;
        }
        ListNode* smaller = new ListNode(0);
        ListNode* dummy = new ListNode(0);  // 用来记录旧链表的其实
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* tmp = smaller;
        while(cur->next) {
            if (cur->next->val < x) {
                tmp->next = cur->next;
                tmp = tmp->next;
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        tmp->next = dummy->next;
        delete dummy;
        return smaller->next;
    }
};
