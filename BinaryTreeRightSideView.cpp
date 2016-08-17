/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 基本思路, 层级遍历整颗树, 并将每一层最后一个节点的值保留下来
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
                first.swap(second);
                second = queue<TreeNode*>();
            }
        }
        return res;
    }
};
