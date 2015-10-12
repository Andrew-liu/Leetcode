// 是上一个题的变种, 需要考虑nums[mid] == nums[right] != target的情况, 这种情况下, 应该搜索left : right - 1(无法排除掉一半)
// 3 1 2 3 3 3 3
// 3 3 3 3 1 2 3
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0, right = len - 1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[mid] < nums[right]) { //右半边有序
                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] > nums[right]) {  //左半边有序
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { //nums[mid] == nums[right]
                right--;
            }
        }
        return false;
    }
};
