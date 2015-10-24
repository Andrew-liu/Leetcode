class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, len = nums.size(), res = len + 1;
        if(len == 0) {
            return 0;
        }
        while(right < len) {
            while(sum < s && right < len) {  //首先右指针右移, 第一个符合大于s的位置
                sum += nums[right++];
            }
            while(sum >= s) {  // 然后左指针右移, 如果小于s则停止, 进入下一次循环
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == len + 1 ? 0 : res;
    }
};
