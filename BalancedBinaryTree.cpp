/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * (1) 一个binary tree中有任何一个subtree不平衡，那么整个tree不平衡。
 * (2) 当x->left和x->right的subtree都平衡时，只有abs(depth(x->left) - depth(x->right))<=1时，以x的subtree才平衡。
 * 自底向上的思考方式, 叶子节点的左右深度都为0, 可以得到叶子节点为max(0, 0) + 1, 然后向上一层节点, max(1, 1) + 1 一次类推
 * 
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return findDepth(root) == -1 ? false : true;
    }
    
    int findDepth(TreeNode* root) {
        if (root == NULL) { //根节点的深度为0
            return 0;
        }
        int left_depth = findDepth(root->left);  // 左子树的深入
        if (left_depth == -1) {
            return -1;
        }
        int right_depth = findDepth(root->right);
        if (right_depth == -1) {
            return -1;
        }
        if (abs(left_depth - right_depth) > 1) {
            return -1;
        }
        return max(left_depth, right_depth) + 1; //叶子0点返回深度(高度)为0, 而实际高度应该为1
        /*
         * 叶子节点左右子树深入为0, 返回后, 叶子节点深入为1, max(0, 0) + 1
         */
    }
};
