/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /*
  * idea: 如果一个节点左子树有两个目标节点中的一个，右子树没有，那这个节点肯定不是最小公共祖先。如果一个节点右子树有两个目标节点中的一个，左子树没有，那这个节点肯定也不是最小公共祖先。只有一个节点正好左子树有，右子树也有的时候，才是最小公共祖先。
  */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 发现目标节点则通过返回值标记该子树发现了某个目标结点
        if(root == NULL || root == p || root == q) {
            return root;
        }
        //查看左子树中是否有目标结点，没有为NULL.
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        //查看右子树是否有目标节点，没有为NULL
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        //都不为空，说明做右子树都有目标结点，则公共祖先就是本身
        if(left != NULL && right != NULL) {
            return root;
        }
        //如果发现了目标节点，则继续向上标记为该目标节点
        return left == NULL ? right : left;
    }
};
