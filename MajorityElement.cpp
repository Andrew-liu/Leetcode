class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2; // 出现次数超过一半的数, 排序后必然处在中间位置
        return nums[mid]; 
    }
};
