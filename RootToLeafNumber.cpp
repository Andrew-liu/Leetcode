/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<int> res;
        int once = 0, sum = 0;
        Traversal(root, once, res);
        cout << "size" << res.size() << endl;
        for(int i = 0; i < res.size(); ++i) {
            cout << "res" <<res[i] << endl;
            sum += res[i];
        }
        return sum;
    }
    bool Traversal(TreeNode* root, int once, vector<int>& res) {
        if(root == NULL) {
            return false;
        }
        once = once * 10 + root->val;
        cout << once << endl; 
        if(root->left == NULL && root->right == NULL) { //叶子节点
            res.push_back(once);
        }
        return Traversal(root->left, once, res) || Traversal(root->right, once, res);
    }
};
int main(int argc, const char *argv[])
{
    TreeNode root(9);
    Solution s;
    cout << s.sumNumbers(&root) << endl;
    return 0;
}
