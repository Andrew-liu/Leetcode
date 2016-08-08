/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 通过题目分析, 可以使用深度优先遍历
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return isSumExist(root, sum, 0);
    }
    // temp用于记录深度优先遍历中间累加和
    bool isSumExist(TreeNode* root, int sum, int temp) {
        if (root == NULL) {
            return false;
        }
        temp += root->val;
        // 深度优先遍历到达叶子节点
        if (root->left == NULL && root->right == NULL) {
            if (temp == sum) { // 到达叶子节点, 表示某一条路径深度优先遍历结束, 则判断当前temp是否等于sum
                return true;
            } else {
                return false;
            }
        }
        // 如果不是叶子节点, 则继续进行深度优先遍历(分别遍历左子树和右子树)
        return isSumExist(root->left, sum, temp) || isSumExist(root->right, sum, temp);
    }
};
