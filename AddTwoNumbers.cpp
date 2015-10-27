/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //题意: 两个链表, 每个链表节点存储一个数字, 并且数字是逆序存储, 然后计算两个字链表中数字之和.
 // 题中的例子 => 342 + 465 = 807 => 7->0->8
 // 使用carry记录进位, 并把进位加到下一次循环的累加中
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0; //进位
        while(l1 != NULL || l2 != NULL || carry != 0) { //注意要求满足条件l1 l2都结尾并且carry为0(表示已经没有进位)
            if(l1) {
                carry += l1->val; 
                l1 = l1->next;
            }
            if(l2) {
                carry += l2->val;  //从最低位开始, l1 l2都累加到carry
                l2 = l2->next;
            }
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            cur = cur->next;
        }
        return dummy->next;
    }
};
