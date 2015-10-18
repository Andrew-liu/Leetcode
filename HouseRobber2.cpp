// 由于现在房间变为环形, 则不能同时抢劫第一个房子和最后一个房子, 所以考虑两种情况: 1. 去掉第一栋房子算其他房子的最大值
// 2. 去掉最后一个房子的抢其他房子的最大值
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.empty() ? 0 : nums[0];
        }
        vector<int> dp1;  //第一个房子未被盗, 第二个房子被盗, 从第三间到最后一间使用DP
        dp1.push_back(0);
        dp1.push_back(nums[1]);
        for(int i = 2; i < nums.size(); ++i) {
            dp1.push_back(max(nums[i] + dp1[i - 2], dp1[i - 1]));
        }
        vector<int> dp2; //第一个房子被盗, 第二个房子未被盗, 最后房子不能被盗, 中间剩余的使用DP
        dp2.push_back(nums[0]);
        dp2.push_back(nums[0]);
        for(int i = 2; i < nums.size() - 1; ++i) {
            dp2.push_back(max(nums[i] + dp2[i - 2], dp2[i - 1]));
        }
        return max(dp1.back(), dp2.back());
    }
};

