/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <string>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 *  前序遍历整个二叉树, 然后链起来, 使用stack回溯, 使用queue存储节点(先进先出)
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> temp;
        queue<TreeNode*> res;
        if(root == NULL) {
            return;
        }
        TreeNode* cur = root;
        while(cur || !temp.empty()) {
            while(cur) {
                temp.push(cur);
                res.push(cur);
                cur = cur->left;
            }
            cur = temp.top();
            temp.pop();
            cur = cur->right;
        }
        res.pop();  //去掉第一个节点, 根节点
        cur = root;
        while(!res.empty()) {
            cur->right = res.front();
            cur->left = NULL;  //别忘了将左子树给清空
            res.pop();
            cur = cur->right;
        }
    }
};
