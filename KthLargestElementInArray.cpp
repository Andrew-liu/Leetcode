// 最简单的方法, 直接快速排序, 然后使用下标返回第k个元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
