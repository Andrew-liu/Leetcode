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

 /*
  * 思路: 深度优先遍历的变种题, 应该使用一个变量还缓存已经走过的路径
  * 分三种情况, 1. 左右子树均为空, 表示已经到叶节点, 此条路径结束, 
  * 2. 左子树为空, 则递归深度遍历右子树, 3. 右子树为空, 则递归的遍历左子树
  */
class Solution1 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        vector<int> nodes;
        helper(root, nodes, paths);
        return paths;
    }
    void helper(TreeNode* node, vector<int>& nodes, vector<string>& paths) {
        if (node == NULL) { // 节点为空时
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            stringstream ss;
            for (int i = 0; i < nodes.size(); ++i) {
                ss << nodes[i] << "->";
            }
            ss << node->val; // 放入最后一个节点
            paths.push_back(ss.str());
            return;
        }
        nodes.push_back(node->val);
        helper(node->left, nodes, paths);
        helper(node->right, nodes, paths);
        nodes.pop_back();  // 回退
    }
};

int main(int argc, char** argv) {
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    Solution1 s;
    vector<string> temp = s.binaryTreePaths(&root);
    for(std::vector<std::string>::size_type ix = 0;
        ix != temp.size(); ++ix) {
        cout << "index: " << ix << " value: " << temp[ix] << endl;
    }
    std::cout << "size: " << temp.size() << std::endl;
}
