// 最简单的方法, 直接快速排序, 然后使用下标返回第k个元素 nlogn的解法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
// 当使用快速的划分方法后, 第一个划分元素, 一定是index+ 1 元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findK(nums, 0, nums.size() - 1, k);
    }
private:
    int findK(vector<int>& nums, int start, int end, int k) {
        int i = start;
        int j = end;
        int povit = nums[start]; //始终以最左边的元素最为起点
        int temp;
        while(i < j) {
            while(nums[j] > povit && i < j)  //从后向前找第一个比povit小的元素
                j--;
            while(nums[i] <= povit && i < j)   //从前向后找第一个比povit大的元素
                i++;
            if(i >= j) {  //当前povit的元素位置正确
                break;
            }
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        nums[start] = nums[i];
        nums[i] = povit;
        if(k < (end - i + 1)) {
            return findK(nums, i + 1, end, k);
        } else if (k > (end - i + 1)) {
            return findK(nums, start, i - 1, k - (end - i + 1));
        } else {
            return nums[end - (k -1)];
        }
    }
};
