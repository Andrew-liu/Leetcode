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

int main(int argc, char** argv) {
    ListNode root(1);
    ListNode foo1(2);
    ListNode foo2(3);
    root.next = &foo1;
    foo1.next = &foo2;
    Solution s;
    cout << s.isPalindrome(&root) << endl;
}
