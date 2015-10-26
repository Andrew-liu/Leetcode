// 类似与3Sum Closestm, 使用对撞指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //题目要求返回的必须是非降序的
        int min_offset = INT_MAX, len = nums.size(); // 作为和0比较的距离
        vector<vector<int> > res;
        if(len == 0) {
            return res;
        }
        for(int i = 0; i < len - 2; ++i) {
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int second = i + 1, third = len - 1, sum = 0 - nums[i]; //sum此时就变成了2sum问题了
                while(second < third) {
                    if(nums[second] + nums[third] == sum) {
                        vector<int> once;
                        once.push_back(nums[i]);
                        once.push_back(nums[second]);
                        once.push_back(nums[third]);
                        res.push_back(once);
                        while(second < third && nums[second] == nums[second + 1]) {
                            ++second;
                        }
                        while(second < third && nums[third] == nums[third - 1]) {
                            --third;
                        }
                        ++second;
                        --third;
                    } else if(nums[second] + nums[third] < sum) {
                        ++second;
                    } else {
                        --third;
                    }
                }
            }
        }
        return res;
    }
};
