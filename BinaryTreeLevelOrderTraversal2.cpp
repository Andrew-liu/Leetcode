/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 总体思想: 使用双队列来进行层级遍历
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) {  // 空树的情况
            return res;
        }
        queue<TreeNode*> parent_q, child_q;
        parent_q.push(root);  //父队列来缓存的当前遍历层的节点
        vector<int> temp; //记录一层的值
        while(!parent_q.empty()) {
            TreeNode* temp_node = parent_q.front();
            parent_q.pop();
            temp.push_back(temp_node->val);
            // 当左子树或者右子树不为空时, 则队列继续遍历
            if (temp_node->left != NULL) { 
                child_q.push(temp_node->left);
            }
            if (temp_node->right != NULL) {
                child_q.push(temp_node->right);
            }
            if(parent_q.empty()) {  // 父队列为空时,表示当前层遍历结束, 则清空temp vector,交换父子队列
                res.push_back(temp);
                temp.clear();
                parent_q.swap(child_q); //父子queu交换元素, 此时子队列为空
            }
        }
        reverse(res.begin(), res.end()); //翻转整个res
        return res;
    }
};
