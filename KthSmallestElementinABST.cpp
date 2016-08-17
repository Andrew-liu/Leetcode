/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 使用二叉搜索树的特性: 在中度遍历时,会获得一个有序的数组, 可以直接O(1)得到第k小的元素
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> cache; //栈可以用于节点的向上回溯
        vector<int> res;
        TreeNode* cur = root;
        while(cur || !cache.empty()) {
            while (cur) {
                cache.push(cur);
                cur = cur->left; //一直向左遍历
            }
            cur = cache.top();
            cache.pop();
            res.push_back(cur->val);
            cur = cur->right; //继续遍历当前节点的右子树
        }
        return res[k - 1];
    }
};
