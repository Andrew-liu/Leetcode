/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * 借用中序遍历的特性, 左, 中, 右
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> temp;
        vector<int> res;
        TreeNode* cur = root;
        while(cur || !temp.empty()) {
            while(cur) {  // 所有左节点的遍历
                temp.push(cur);
                cur = cur->left;
            }
            cur = temp.top();
            temp.pop();
            res.push_back(cur->val);
            cur = cur->right;  // 切换到右子树
        }
        return res[k - 1];
    }
};
