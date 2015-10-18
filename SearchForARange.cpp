// 首先使用二分查找找到一个节点, 然后左右扫描找到对应的左右边界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ranges;
        int len = nums.size();
        int index = binarySearch(nums, target);
        if(index == -1) { //没有符合条件的target
            ranges.push_back(-1);
            ranges.push_back(-1);
        } else {  //有符合条件的, 则左右扫描
            int left = index;
            while(left > 0 && nums[left - 1] == nums[index]) {  //向左扫描
                --left;
            }
            int right = index;
            while(right < len - 1 && nums[index] == nums[right + 1]) {
                ++right;
            }
            ranges.push_back(left);
            ranges.push_back(right);
        }
        
        return ranges;
    }
    int binarySearch(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;
        while(beg <= end) {
            int mid = beg + (end - beg) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                end = mid - 1; 
            } else {
                beg = mid + 1;
            }
        }
        return -1;
    }
};
