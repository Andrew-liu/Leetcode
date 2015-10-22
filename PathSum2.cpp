/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //看到第一眼感觉很像回溯法的解法, 后来一想回溯法就是深度优先遍历
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        vector<int> once;
        if(root == NULL) {
            return res;
        }
        once.push_back(root->val);  //根节点特殊处理
        DFS(root, sum - root->val, once, res);
        return res;
    }
    void DFS(TreeNode* root, int sum, vector<int>& once, vector<vector<int> >& res) {
        if(root->left == NULL && root->right == NULL && 0 == sum) {  //终结条件,到达叶子节点, 并且 sum为0
            res.push_back(once);
            return;
        }
        if(root->left) {
            once.push_back(root->left->val);
            DFS(root->left, sum - root->left->val, once, res);
            once.pop_back();
        }
        if(root->right) {
            once.push_back(root->right->val);
            DFS(root->right, sum - root->right->val, once, res);
            once.pop_back();
        }
    }
};
