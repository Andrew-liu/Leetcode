#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 // 广度优先遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector <int> > res;
        vector<int> lvl;
        if(root == NULL)
            return res;
        queue <TreeNode*> st_par, st_chi; //一个用于存放父节点, 一个用于存放子节点
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
        return res;
    }
};

int main(int argc, char** argv) {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;
    Solution s;
    vector<vector<int> > res =  s.levelOrder(&a);
    for(auto num : res) {
        for(auto f : num) {
            cout << f << " ";
        }
        cout << endl;
    }
}
