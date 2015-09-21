// 使用一个新的vector来移动元素, 注意当k大于vector_size的时候, k应该取 k % len
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size(), j = 0;
        if (len < k) {
            k = k % len;
        }
        vector<int> new_nums(nums.size());

        for(int i = len - k; i < len; ++i) {
            new_nums[j++] = nums[i];
        }
        for(int i = 0; i < len - k; ++i) {
            new_nums[j++] = nums[i];
        }
        nums = new_nums;
    }
};
