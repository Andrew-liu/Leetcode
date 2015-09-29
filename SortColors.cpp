// 最傻的方法, 直接遍历暴力法, test case貌似很水, 没有复杂度限制
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> res;
        int len = nums.size(), count = 0;
        while(len) {
            for(int i = 0; i < nums.size(); ++i) {
                if(nums[i] == count) {
                    res.push_back(nums[i]);
                    len--;
                }
            }
            count++;
        }
        nums = res;
    }
};

// 第二种方法, 第一次遍历统计红, 白的个数, 第二次直接覆盖原值
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size(), red = 0, white = 0;
        for(int i = 0; i < len; ++i) {
            if(nums[i] == 0) {
                red++;
            } else if(nums[i] == 1) {
                white++;
            }
        }
        for(int i = 0; i < len; ++i) {
            if(red > 0) {
                nums[i] = 0;
                red--;
                continue;
            }
            if(white > 0) {
                nums[i] = 1;
                white--;
                continue;
            }
            nums[i] = 2;
        }
    }
};
