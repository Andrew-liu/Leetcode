/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {  //两个节点都为空, 表示已经都了叶子节点的后继(并且考虑到1, 0这种特殊case)
            return true;
        }
        if (!p || !q) {  //一个节点为空, 一个节点不为空
            return false;
        }
        // 两个节点都不为空, 则判断节点的值是否相同, 并且递归的判断左子树和右子树
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
