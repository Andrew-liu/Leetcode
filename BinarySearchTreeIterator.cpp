/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 思想: 先中度优先遍历元素并放入队列
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> buffer;
        TreeNode* cur = root;
        while(cur || !buffer.empty()) {  //中度优先遍历
            while(cur) {
                buffer.push(cur);
                cur = cur->left;
            }
            cur = buffer.top();
            buffer.pop();
            res.push(cur);
            cur = cur->right;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return res.empty() ? false : true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = res.front();
        res.pop();
        return cur->val;
    }
private:
    queue<TreeNode*> res;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
