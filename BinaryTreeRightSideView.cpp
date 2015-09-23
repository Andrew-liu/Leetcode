/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //查看二叉树最右边的节点, 找的是每一层最右侧的节点. 直接递归的调用遍历右侧的节点的想法是错误的, 使用BFS的思路
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> first, second;
        first.push(root);
        TreeNode* cur = NULL;
        while(!first.empty()) {
            cur = first.front();
            first.pop();
            if(cur->left) {
                second.push(cur->left);
            }
            if(cur->right) {
                second.push(cur->right);
            }
            if(first.empty()) {
                res.push_back(cur->val);
                first = second;
                second = queue<TreeNode*>();
            }
        }
        return res;
    }
};
