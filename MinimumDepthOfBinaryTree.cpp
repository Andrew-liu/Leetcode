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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;  // 递归的终结点
        }
        // 递归深度遍历左右子树
        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);
        if (left_depth == 0 && right_depth == 0) {
            return 1; //只有根节点的情况
        }
        // 只有右子树的情况(注意此时左子树没有叶子节点!无法求深度)
        if (left_depth == 0) {
            left_depth = INT_MAX;
        }
        // 只有左子树的情况(注意此时右子树没有叶子节点!)
        if (right_depth == 0) {
            right_depth = INT_MAX;
        }
        return min(right_depth, left_depth) + 1;
    }
};
