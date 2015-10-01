/*
 * 1.从右向左找到第一个符合 nums[index - 1] < nums[index]的元素, index - 1对应的下标为分割点
 * 2.从右向左找到一个元素符合 nums[index - 1] < nums[large]
 * 3.将两个index - 1和large的下标对应的元素交换
 * 4.对index(不是index - 1)开始到最后的元素排序
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 找到分割点
        int len = nums.size() - 1, index;
        for(index = len; index > 0; index--) {
            if(nums[index - 1] < nums[index]) {  //找到分割点的后一个位置
                break;
            }
        }
        if(index > 0) {
            index--;  //分割点的正确下标
            int large_index = len;
            while(large_index >= 0 && nums[index] >= nums[large_index]) {  //从右向左找到一个比分割点的元素
                large_index--;
            }
            swap(nums[index], nums[large_index]);
            index++; //设置为分割点的下一个位置
        }
        sort(nums.begin() + index, nums.end()); //对分割点下一个位置到尾部的元素排序
    }
};
