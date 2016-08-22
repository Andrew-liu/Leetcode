/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 深度优先遍历的变种
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<int> res;
        int once = 0, sum = 0;
        Traversal(root, once, sum);
        return sum;
    }
    void Traversal(TreeNode* root, int once, int& res) {
        if(root == NULL) {
            return;
        }
        once = once * 10 + root->val;
        if(root->left == NULL && root->right == NULL) { //叶子节点
            res += once;  // 到达叶子节点, 说明一次从root到叶子节点的深度遍历结束
        }
        Traversal(root->left, once, res);
        Traversal(root->right, once, res);
    }
};
