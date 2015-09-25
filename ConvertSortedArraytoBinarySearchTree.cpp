tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 按照中间节点为root, 左边的元素为左子树, 右边的元素为右子树,  然后对左边的所有元素进行建树, 右边的所有元素进行建树, 递归的调用
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBalanceTree(nums, 0, nums.size() - 1);
    }
    TreeNode* makeBalanceTree(vector<int>& nums, int left, int right) {
        int mid = (left + right) / 2;
        if(left > right) { // 零个元素情况, left = 0, right = -1
            return NULL;
        }
        if(left == right) {  // 只有一个元素的情况
            return new TreeNode(nums[left]);
        }
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeBalanceTree(nums, left, mid -1);
        root->right = makeBalanceTree(nums, mid + 1, right);
        return root;
    }
};
