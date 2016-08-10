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

 // 回溯法当前节点的所有path已经都访问到了，返回前需要从path中删除当前节点，以便重新构建其他path
 // 回溯法也是深度优先遍历
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path; //单条路径
        vector<vector<int> > paths;  //所有路径
        helper(root, sum, path, paths);
        return paths;
    }
    void helper(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (node == NULL) {
            return;
        }
        sum -= node->val;
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            if (sum == 0) {
                paths.push_back(path);
            }
        }
        helper(node->left, sum, path, paths);
        helper(node->right, sum, path, paths);
        //回溯
        path.pop_back();
    }
};
