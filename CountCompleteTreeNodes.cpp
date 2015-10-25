/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//最简单的广度优先遍历
//不过显然这个方法超时了, 这道题应该需要使用完全二叉树的性质: 除了叶子节点层, 其他层的节点都是满的
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> buf;
        if(root == NULL) {
            return 0;
        }
        int total = 0;
        buf.push(root);
        while(!buf.empty()) {
            total += buf.size();
            int level = buf.size();
            while(level-- > 0) {  //遍历当前层的元素, 并把他们的左右子树入队
                TreeNode* cur = buf.front();
                buf.pop();
                if(cur->left != NULL) {
                    buf.push(cur->left);
                }
                if(cur->right != NULL) {
                    buf.push(cur->right);
                }
            }
        }
        return total;
    }
}; 

//递归解法: (完全二叉树的性质: 除了最后一层节点, 其他层全都是满的, 所有节点总个数(树高h) : 2^(h - 1) - 1 + 加上最后一层节点数)
//如果完全二叉树为满二叉树, 则节点数 2 ^ h - 1
//找出最左和最右节点的高度比较, 如果相等则说明是满二叉树, 返回节点个数, 
//如果不相等, 则节点个数为左子树的节点个数 + 右子树的节点个数 + 1(根节点)
class Solution {
public:
    int countNodes(TreeNode* root) {
        int lHeight = 0, rHeight = 0;
        TreeNode *leftNode = root, *rightNode = root;
        while(leftNode != NULL) {
            lHeight++;
            leftNode = leftNode->left;
        }
        while(rightNode != NULL) {
            rHeight++;
            rightNode = rightNode->right;
        }
        if(lHeight == rHeight) {  //说明是满二叉树
            return pow(2, lHeight) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
