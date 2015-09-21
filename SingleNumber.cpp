// 0和num异或结果为num, num和num异或结果为0, num1 num1 num2 num2 num3 一起异或, 记过必然是num3, 其他的两两异或为0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0, len = nums.size();
        for(int i = 0; i < len; ++i) {
            res ^= nums[i];
        }
        return res;
    }
};
