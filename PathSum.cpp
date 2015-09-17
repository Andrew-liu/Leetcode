/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //思考考虑深度优先遍历DFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return isPathSum(root, sum, 0);
        
    }
    bool isPathSum(TreeNode* root, int sum, int temp) {
        if (root == NULL) {  //根节点为空
            return false;
        }
        temp += root->val;
        if(root->left == NULL && root->right == NULL) { //叶子节点
            if(temp == sum) { //叶子节点时, 判断temp累加和和sum是否相等
                return true;
            } else {
                return false;
            }
        }
        //不是叶子节点继续递归的遍历
        return isPathSum(root->left, sum, temp) || isPathSum(root->right, sum, temp);  //递归遍历
    }
};
