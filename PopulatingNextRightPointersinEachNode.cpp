/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 //直觉思路是BFS, 使用两个队列, 一个队列管理一层的节点. 当当前层队列没有元素时, 将next = NULL, 否则, next = 当前队列的头结点
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
            if(cur->left != NULL) {
                    second.push(cur->left);
                } 
            if (cur->right != NULL) {
                second.push(cur->right);
            }
            if (first.empty()) {  //没有后继节点了
                cur->next = NULL;
                first = second;  //将second复制给first
                second = queue<TreeLinkNode*>();
            } else {  //还有后继节点
                cur->next = first.front();
            }
        }
    }
};
