// 又是一个回溯法求解的问题, 思路和之前的差不多
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> once;
        vector<bool> used(nums.size(), false); //用于记录某一位是否已经使用, 防止重复
        helper(nums, used, once, res);
        return res;
    }
    void helper(vector<int>& nums, vector<bool>& used, vector<int>& once, vector<vector<int> >& res) {
        if(once.size() == nums.size()) { //终止递归条件
            res.push_back(once);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(used[i] == true) { //如果已经使用了, 则跳过
                continue;
            }
            used[i] = true;
            once.push_back(nums[i]);
            helper(nums, used, once, res);
            used[i] = false;
            once.pop_back();
        }
    }
};
