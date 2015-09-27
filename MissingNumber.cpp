class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size(), sum = 0;
        if(nums[0]  == 1 && len == 1) {
            return 0;
        }
        if(len == 1) {
            return nums[0] + 1;
        }
        for(int i = 0; i < len; ++i) {
            sum += nums[i];
        }
        return len * (len + 1) / 2 - sum;
    }
};
