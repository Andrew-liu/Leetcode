/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * 思路: 首先遍历链表获取长度, 然后找到正向的位置, 再遍历找到前驱
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
            return head;
        }
        int len = 0;
        ListNode* cur = head;
        while(cur != NULL) {
            cur = cur->next; 
            len++;
        }
        int pre_loc = len - n; //获取要删除节点前驱的位置
        cur = head;
        if (pre_loc == 0) {  //要删除的为第一个节点
            head = head->next;
            return head;
        }
        pre_loc--; //减一才能够找到前驱节点的位置, 不建议找到的是删除节点的位置
        while(pre_loc != 0) {
            pre_loc--;
            cur = cur->next;
        } //跳出循环后, cur指向删除节点的前驱
        cur->next = cur->next->next;
        return head;
    }
};

//更好的解法, 使用快慢指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* dummy = new ListNode(0);  //可能删除头结点
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(n--) {
            fast = fast->next;
        }
        while(fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
