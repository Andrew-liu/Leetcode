/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * 中序遍历 (左->中->右)
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        inorder(root, res);
        return res;
    }
    void inorder(TreeNode* root, vector<int>& res) {
        if(root == NULL) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);  // 注意在此处才将数据放入队列
        inorder(root->right, res);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * 非递归的实现非常类似先序遍历, 不断将左节点入栈,  然后当前栈顶节点top并pop, 然后进入vector. 并循环判断当前节点的右子树
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> temp; 
        TreeNode* cur = root;
        while(cur != NULL || !temp.empty()) {
            while(cur != NULL) {
                temp.push(cur);
                cur = cur->left; //所有左侧的节点入栈
            }
            cur = temp.top();
            temp.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
