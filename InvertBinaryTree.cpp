
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        // 交换当前节点的左右指针(不是只交换两个Node的值)
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;
        // 递归调用
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
