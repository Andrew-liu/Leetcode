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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {  //如果一个链表为空, 表示没有交点
            return NULL;
        }
        //遍历两个链表, 并记录链表长度(总长度 - 1), 保存两个链表的尾指针
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 1, lenB = 1;
        while(curA->next != NULL) {
            curA = curA->next;
            lenA++;
        }  //循环结束后, curA指向链表的最后一个节点
        while(curB->next != NULL) {
            curB = curB->next;
            lenB++;
        } // 循环结束后, curB指向链表的最后一个节点
        if(curA != curB) {
            return NULL;  //不指向同一个尾节点说明不是相交的
        }
        if(lenA > lenB) {
            int offset = lenA - lenB;
            ListNode* curA = headA;
            ListNode* curB = headB;
            while(offset > 0) { //此时两个指针处于同一长度的起步点, 然后一起开始移动
                curA = curA->next;
                offset--;
            }
             while(curA != NULL && curB != NULL) {
                 if(curA == curB) {
                     return curA;
                 }
                 curA = curA->next;
                 curB = curB->next;
             }
        } else {
            int offset = lenB - lenA;
            ListNode* curA = headA;
            ListNode* curB = headB;
            while(offset > 0) { //此时两个指针处于同一长度的起步点, 然后一起开始移动
                curB = curB->next;
                offset--;
            }
             while(curA != NULL && curB != NULL) {
                 if(curA == curB) {
                     return curA;
                 }
                 curA = curA->next;
                 curB = curB->next;
             }  
        }
    }
};
