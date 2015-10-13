class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int flag = 1, offset = 1;  //offset标记当前元素应该移动的位置
        for(int i = 1; i < len; ++i) {
            if(nums[i - 1] == nums[i] && flag != 0) {
                --flag;  //flag用于标记只有2个重复, 
                nums[offset++] = nums[i]; 
            } 
            if(nums[i - 1] != nums[i]) {
                flag = 1;
                nums[offset++] = nums[i];
            }
        }
        return offset;
    }
};
