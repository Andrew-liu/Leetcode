// 这道题确认是medium级别的? 怎么会这么简单, 直接O(n)求解
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if(target == nums[i]) {
                return i;
            } else if(target < nums[i]) {
                return i;
            } 
        }
        return len;
    }
};

// 另一种解法: 二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            } 
            if (left < mid && nums[mid] > target && nums[mid - 1] < target) {
                return mid;  //处在数组中某两个数中间
            }
            if (nums[mid] > target) {
                right = mid - 1;  //说明查询的数在左边
            } else {
                left = mid + 1;  //说明查询的数在右边
            }
        }
        if (target > nums[nums.size() - 1]) {  //处理比所有数都大的情况, 不特殊处理的话会返回size() - 1
            left = nums.size();
        }
        return left;
        
    }
};
