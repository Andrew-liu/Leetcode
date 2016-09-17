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
  * 题目大意:给的是二叉搜索树，寻找其中两个给定节点的最近公共祖先（LCA）。
  * 根据维基百科对LCA的定义：
  * 节点v与w的最近公共祖先是树T上同时拥有v与w作为后继的最低节点（注意这句话: 允许将一个节点当做其本身的后继）
  */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        //1. p, q都比root小，则LCA在左树，继续在左树中寻找LCA
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        //2. p, q都比root大，则LCA在右树，继续在右树中寻找LCA
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        //3. 其他情况，表示p, q在root两边，或者二者其一是root，或者都是root，这些情况表示root就是LCA
        } else {
            return root;
        }
    }
};
