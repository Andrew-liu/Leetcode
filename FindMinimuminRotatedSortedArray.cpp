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

// 二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        int temp = nums[0], left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] >= nums[right]) { //说明后半段比较小, 则较小的数字在后半段
                left = mid + 1;
            } else {  //说明比较小的在前半段, 
                right = mid - 1;
            }
            temp = min(temp, nums[mid]);
        }
        return temp;
    }
};
