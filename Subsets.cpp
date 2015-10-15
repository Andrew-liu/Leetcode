// 依然使用回溯法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res(1, vector<int>()); // 子集比有一个空集
        vector<int> once;
        sort(nums.begin(), nums.end());  // 使数组有序
        helper(nums, 0, once, res);
        return res;
    }
    void helper(vector<int> nums, int start, vector<int>& once, vector<vector<int> >& res) {
        for(int i = start; i < nums.size(); ++i) {
            once.push_back(nums[i]);
            res.push_back(once);
            if(i + 1 <= nums.size() - 1) {
                helper(nums, i + 1, once, res);
            }
            once.pop_back();
        }
    }
};
