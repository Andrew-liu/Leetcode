/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 递归解法: 1. 当左右都为空,true 2. 左右一个为空一个不空, 则为false, 3, 如果值不相等, 为false, 4. 递归左边节点的左子树和右边节点的右子树, 5. 递归左边节点的右子树和右边节点的左子树
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSym(root->left, root->right);
    }
    bool isSym(TreeNode* l, TreeNode* r) {
        if(l == NULL && r == NULL) {
            return true;  //左边和右边都为空 (不是左右子树)
        } else if(l == NULL || r == NULL) {
            return false; //左边为空右边不同, 右边为空, 左边不空
        }
        if(l->val != r->val) {
            return false;  // 左右不为空, 但值不相同
        }
        /*
        if(!isSym(l->left, r->right)) { //最左边和最右边比较是否对称
            return false;
        }
        if(!isSym(l->right, r->left)) { //一个节点的右边和另一个节点的左边
            return false;
        }
        return true; // 表示对称
        */
        return isSym(l->left, r->right) && isSym(l->right, r->left); // 更加简单的解法, 两个判断必须同时成立, true才会返回
    }
}; 
