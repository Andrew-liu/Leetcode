/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * 使用类似与两个链表排序的方法, 归并排序, 找到中间节点, 然后进行排序
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL) { // 找到链表的中间节点, 然后进行归并
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        ListNode* head1 = head;
        head1 = sortList(head1); // 对前半段排序
        head2 = sortList(head2); // 对后半段排序
        return merge(head1, head2);  //对整个排序
    }
    //归并两个有序链表
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if(head1 == NULL) {
            return head2;
        } 
        if(head2 == NULL) {
            return head1;
        }
        ListNode *head, *cur = NULL;
        if(head1->val <= head2->val) { //确定头结点
            head = head1;
            head1 = head1->next;
        } else {
            head = head2;
            head2 = head2->next;
        }
        cur = head; //设置移动的尾节点用于插入
        while(head1 && head2) {
            if(head1->val <= head2->val){
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if(head1) {
            cur->next = head1; //第一个链表有剩余
        }
        if(head2) {  //第二个链表有剩余
            cur->next = head2;
        }
        return head;
    }
};
