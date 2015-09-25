/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 还有一种简单方法, 类似与数组的解法, 每次遍历单链表使用快慢指针找中间节点
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode *cur = head;
        while(cur) {  // 计算链表的长度
            len++;
            cur = cur->next;
        }
        return makeBST(head, 0, len - 1);
    }
    TreeNode* makeBST(ListNode *&head, int left, int right) {
        if(left > right) {
            return NULL; //链表为空
        }
        int mid = left + (right - left) / 2;  //计算中间节点
        TreeNode *left_node = makeBST(head, left, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *right_node = makeBST(head, mid + 1, right);
        root->left = left_node;
        root->right = right_node;
        return root;
    }
};
