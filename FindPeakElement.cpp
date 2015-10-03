// 二分查找
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) {
            return 0;
        }
        int beg = 0;
        int end = len - 1;
        int mid;
        while(beg <= end) {
            mid = beg + (end - beg) / 2;
            if ((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == len - 1 || nums[mid] >= nums[mid + 1])) {
                return mid;
            } else if (nums[mid] < nums[mid + 1]) {  //峰值在右边
                beg = mid + 1;
            } else {  //峰值在左边
                end = mid - 1;
            }
        }
        return mid;
    }
};
