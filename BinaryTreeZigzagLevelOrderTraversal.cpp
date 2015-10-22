 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 思路广度优先遍历, 然后有一个flag记录方向, 思路错误(顺序会乱掉), 
 * 使用双栈(或者双队列), 分别存储两层的数据
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) {
            return res;
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        vector<int> once;
        while(!s1.empty() || !s2.empty()) {
            while(!s1.empty()) {
                TreeNode* cur = s1.top();
                s1.pop();
                once.push_back(cur->val);
                if(cur->left) {  //入栈和出栈的顺序刚好相反
                    s2.push(cur->left);
                }
                if(cur->right) {
                    s2.push(cur->right);
                }
            }
            if(!once.empty()) {
                res.push_back(once);
            }
            once.clear();
            while(!s2.empty()) {
                TreeNode *cur = s2.top();
                s2.pop();
                once.push_back(cur->val);
                if(cur->right) {
                    s1.push(cur->right);
                }
                if(cur->left) {
                    s1.push(cur->left);
                }
            }
            if(!once.empty()) {
                res.push_back(once);
            }
            once.clear();
        }
        return res;
    }
}; 
