// 贪婪算法
class Solution {
public:
    int jump(vector<int>& nums) {
        int last = nums.size() - 1, res = 0, i = 0, cur = 0;
        while(cur < last) {
            int pre = cur;
            while(i <= pre) {
                cur = max(cur, i + nums[i]);
                ++i;
            }
            ++res;
            if(pre == cur) {
                return -1;
            }
        }
        return res;
    }
};
