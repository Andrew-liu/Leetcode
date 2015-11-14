/*
思路: 数组排序, 排序规则: a, b两个数字, 转换成字符串 如果'ab'>'ba'. 则a排在前面, 否则b排在前面
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        for(int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res[0] == '0' ? "0" : res;
    }
};
