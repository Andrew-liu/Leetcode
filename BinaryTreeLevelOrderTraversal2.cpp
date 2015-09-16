/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector <int> > res;
        vector<int> lvl;
        if(root == NULL)
            return res;
        queue <TreeNode*> st_par, st_chi;
        TreeNode* curr = root;
        st_par.push(curr);
        while(!st_par.empty()){
            curr = st_par.front();
            st_par.pop();
            if(curr->left)
                st_chi.push(curr->left);
            if(curr->right)
                st_chi.push(curr->right);
            lvl.push_back(curr->val);
            if(st_par.empty()){
                while(!st_chi.empty()){  //将子队列的节点写入到父队列中z
                    st_par.push(st_chi.front());
                    st_chi.pop();
                }
                res.push_back(lvl);
                lvl.clear();
            }
        }
        reverse(res.begin(), res.end());  //元素翻转就行了
        return res;    
    }
};
