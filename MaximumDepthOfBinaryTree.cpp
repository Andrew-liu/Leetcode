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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;  // 递归终止条件, 让叶子节点时, 返回0
        }
        int left_max = maxDepth(root->left);  //递归的求左子树的最大深度
        int right_max = maxDepth(root->right);  // 递归的求右子树的最大深度
        return max(left_max, right_max) + 1;  //叶子0点返回深度(高度)为0, 而实际高度应该为1
    }
};
