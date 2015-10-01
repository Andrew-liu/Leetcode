class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> once;
        vector<vector<int> > res;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); //排序后方便判断前后是否元素相等
        helper(nums, used, once, res);
        return res;
    }
    void helper(vector<int>& nums, vector<bool>& used, vector<int>& once, vector<vector<int> >& res) {
        if(once.size() == nums.size()) {
            res.push_back(once);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(used[i] == true) { //表示已经使用过
                continue;
            }
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) { //相等的时候则前面的数必须使用了，自己才能使用
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
