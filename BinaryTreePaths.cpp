#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path = "";
        if(root == NULL) {
            return paths;
        }
        DFS(root, path, paths);
        return paths;
    }
    void DFS(TreeNode *root, string path, std::vector<string>& paths) {
        TreeNode *cur = root;
        if (cur->left == NULL && cur->right == NULL) {
            stringstream ss;
            ss << cur->val;
            return paths.push_back(path.append(ss.str()));
        }
        if (cur->left) {
            stringstream ss;
            ss << cur->val;
            string left_path = path + ss.str() + "->";
            // cout << path << endl;
            DFS(cur->left, left_path, paths);
        }
        if (cur->right){
            stringstream ss;
            ss << cur->val;
            string right_path = path + ss.str() + "->";
            cout << right_path << endl;
            DFS(cur->right, right_path, paths);
        }
    }
};

int main(int argc, char** argv) {
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    Solution s;
    vector<string> temp = s.binaryTreePaths(&root);
    for(std::vector<std::string>::size_type ix = 0;
        ix != temp.size(); ++ix) {
        cout << temp[ix] << endl;
    }
}