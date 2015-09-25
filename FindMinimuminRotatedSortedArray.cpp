// 无脑方法被AC了, 
class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) { // 找第一个i - 1的元素大于i
                return nums[i];
            }
        }
        return nums[0];
    }
};
