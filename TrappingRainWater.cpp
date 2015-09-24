#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int trap(vector<int>& nums) {
        int res = 0, len = nums.size(), left = 0;
        if(len <= 1) {
            return 0;
        }
        vector<int> left_max(len, 0);  // 记录从当前下标左侧的最大值
        for (int i = 0; i < len; ++i) {
            if (nums[i] > left) {
                left = nums[i];
            }
            left_max[i] = left; // 存储左侧最大值
        }
        int sum = 0, right_max = 0;
        //逆序遍历求判断每个元素右侧最大值
        for(int i = len - 1; i >= 0; --i) {
            if(nums[i] > right_max) {
                right_max = nums[i];  //存储右侧最大值
            }
            if(min(right_max, left_max[i]) > nums[i]) {
                sum += min(right_max, left_max[i]) - nums[i];
            }
        }
        return sum;
    }
};

int main(int argc, char** argv) {
    int ia[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> nums(ia, ia + 12);
    for(auto num : nums) {
        cout << num << endl;
    }
    Solution s;
    cout << s.trap(nums) << endl;
    return 0;
}
