/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //好吧, 做第一题的方法完全适用于这道题
class Solution {
public:
    void connect(TreeLinkNode *root) {
       if (root == NULL) {
           return;
       }
       queue<TreeLinkNode*> first, second;
       first.push(root);
       TreeLinkNode* cur = NULL;
       while(!first.empty()) {
           cur = first.front();
           first.pop();
           if(cur->left) { 
               second.push(cur->left);
           }
           if(cur->right) {
               second.push(cur->right);
           }
           if(first.empty()) { //此时当了当前层的最后一个节点
               cur->next = NULL;
               first = second;
               second = queue<TreeLinkNode*>();
           } else {
               cur->next = first.front();
           }
           
       }
    }
};
