#include <iostream>
#include <vector>
#include <stack>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 先序遍历的顺序为中->左->右
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        preorder(root, res);
        return res;
    }
    void preorder(TreeNode* root, vector<int>& res) {
        if(root != NULL) {
            res.push_back(root->val);
        } else {
            return;
        }
        
        preorder(root->left, res);
        preorder(root->right, res);
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
 *  非递归的方式: (中->左->右), 当前节点不空, 则进入vector, 然后继续查看左节点入栈, 然后出现当前节点查看是否有右节点
 */
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> temp;
        TreeNode* cur = root;
        while(cur != NULL || !temp.empty()) {
            while(cur != NULL) {
                res.push_back(cur->val);
                temp.push(cur);
                cur = cur->left;
            }
            cur = temp.top();  //获取栈顶元素, 第一个为最左下角的节点
            temp.pop();
            cur = cur->right;
        }
        return res;
    }
};
