/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        stack<int> s;
        s.push(head->val);
        while (fast->next && fast->next->next) {  //找到中间节点
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        if (!fast->next) {  //奇数情况, 去掉中间节点
            s.pop();
        }
        while (slow->next) {
            slow = slow->next;
            int tmp = s.top(); 
            s.pop();
            if (tmp != slow->val) {
                return false;
            }
        }
        return true;
    }
};

 /*
 1. 可是申请额外空间, 则前半段入栈, 和后半段出栈比较
 2. 不可申请, 前半段reverse, 然后分别从两段的头部比较
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) {
            return true;
        }
        ListNode* cur = head;
        int len = 0;
        while(cur != NULL) {
            len++;
            cur = cur->next;
        }
        int half = len / 2;
        int temp = 0;
        ListNode* pre = NULL;
        ListNode* tmp = NULL;
        cur = head;
        while(temp++ < half) {  //翻转前半段
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        if(len % 2 != 0) { //当为奇数时, 指向中间值
            cur = cur->next;
        }
        while(pre && cur) {
            if(pre->val != cur->val) {
                return false;
            }
            pre = pre->next;
            cur = cur->next;
        }
        return true;
    }
};

int main(int argc, char** argv) {
    ListNode root(1);
    ListNode foo1(2);
    ListNode foo2(3);
    root.next = &foo1;
    foo1.next = &foo2;
    Solution s;
    cout << s.isPalindrome(&root) << endl;
}
