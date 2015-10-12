// 有序查找 常用的方法为二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] < nums[right]) { //翻转后, 起始元素在右边 5 6 0 1 2 3 4
                if(nums[mid] < target && target <= nums[right]) { //在半边右侧
                    left = mid + 1;   
                } else {
                    right = mid - 1;
                }
            }else { // 翻转后, 其实元素在左边 2 3 4 5 6 0 1
                if(nums[left] <= target && target < nums[mid]) { //在半边的左侧
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
