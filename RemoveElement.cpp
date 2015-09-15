// 一个取巧的方案, 用新的容器容纳数据, 然后复制给原来的容器
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }
        vector<int> new_nums;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val) {
                new_nums.push_back(nums[i]);
            }
        }
        nums = new_nums;
        return nums.size();
    }
};
