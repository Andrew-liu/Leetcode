//求的最值问题, 使用动态规划来解, dp[i] = max(nums[i] + dp[i - 2], dp[1 - 1]);
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.empty() ? 0 : nums[0];
        }
        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(max(nums[0], nums[1]));  // 初始化dp数组
        for(int i = 2; i < nums.size(); ++i) {
            dp.push_back(max(nums[i] + dp[i - 2], dp[i -1]));
        }
        return dp.back();
    }
};
