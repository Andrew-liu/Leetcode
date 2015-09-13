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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {  //p和q都为空时
            return true;
        } else if (p && q) { // p和q都不为空时
            if (!isEqual(p->val, q->val)) {
                return false;
            } 
            if (isSameTree(p->left, q->left) == false)
                return false;
            if (isSameTree(p->right, q->right) == false)
                return false;
            return true;
        } else {  // p和q一个为空, 一个不为空
            return false;
        }
    }
    bool isEqual(int val1, int val2) {
        return val1 == val2 ? true : false;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {  //两个极点都为空
            return true;
        }
        if (!p || !q) {  //一个节点为空, 一个节点不为空
            return false;
        }
        // 两个节点都不为空, 则考虑他的左右子节点
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isEqual(int val1, int val2) {
        return val1 == val2 ? true : false;
    }
};
