// 找到两个元素, 下标分别i和j, 两个元素的值不超过t, 下标的i和j的值不超过k

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i - j > k && m[nums[j]] == j) {
                m.erase(nums[j++]);  //使map中的元素使用中下标都小于等于k
            }
            auto a = m.lower_bound(nums[i] - t);  // 找到大于或等于nums[i] - t的地方
            if(a != m.end() && abs(a->first - nums[i]) <= t) {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};
