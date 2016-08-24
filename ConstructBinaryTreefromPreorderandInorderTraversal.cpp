/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 先序遍历的第一个节点, 是根节点, 每次按照第一个节点源根结点, 对中序遍历的序列进行划分, 可以找到左右子节点
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
        if (pLeft > pRight || iLeft > iRight) {
            return NULL;
        }
        int i = 0;
        for (i = iLeft; i <= iRight; ++i) {  //找到中间的划分节点(即为当前子树的根节点)
            if (preorder[pLeft] == inorder[i]) { 
                break;
            }
        }
        TreeNode *cur = new TreeNode(preorder[pLeft]);  //每次找到根节点, 然后递归的寻找左右子树的节点
        cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
        cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return cur;
    }
};
