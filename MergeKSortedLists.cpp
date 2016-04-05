/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
   通过二分法减少list之间的比较次数.
   每个list只需要和nlogn个list进行比较, 不需要和n个list进行比较
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        int len = lists.size();
        return mergeHelper(lists, 0, len - 1);
    }
    ListNode* mergeHelper(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        int mid = start + (end - start) / 2;
        ListNode* leftList = mergeHelper(lists, start, mid);
        ListNode* rightList = mergeHelper(lists, mid + 1, end);
        return mergeTwoLists(leftList, rightList);
    }
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
