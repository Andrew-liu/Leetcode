/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 第一感觉, 中序优先遍历(中左右), 查看是否有序, 
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> temp;
        if(root == NULL) {
            return true;
        }
        vector<int> res;
        TreeNode *cur = root, *pre = NULL;
        while(cur ||!temp.empty()) {
            while(cur != NULL) {
                temp.push(cur);
                cur = cur->left;
            }  //放入最左节点
            cur = temp.top();
            temp.pop();
            if (pre == NULL) {
                pre = cur;
            } else {
                if(cur->val <= pre->val) {
                    return false;
                }
            }
            pre = cur;
            cur = cur->right;
        }
        return true;
    }
};

 // 使用递归解法
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }
    bool isValidBST(TreeNode* root, int min_value, int max_value) {
        // 节点为空, 表示为二叉查找树
        if (root == NULL) {
            return true;
        }
        // 当前节点的值小于最小值或者大于最大值, 则表示非二叉查找树
        if (root->val <= min_value || root->val >= max_value) {  
            return false;
        }
        // 否则, 继续递归遍历左右子节点
        return isValidBST(root->left, min_value, root->val) && isValidBST(root->right, root->val, max_value);
    }
};
