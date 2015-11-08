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
