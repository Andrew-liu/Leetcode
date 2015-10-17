class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> once;
        res.push_back(once); //至少有一个空集为子集
        sort(nums.begin(), nums.end());
        helper(nums, 0, once, res);
        return res;
    }
    void helper(vector<int>& nums, int start, vector<int>& once, vector<vector<int> >& res) {
        for(int i = start; i < nums.size(); ++i) {
            once.push_back(nums[i]);
            res.push_back(once);
            if(i + 1 < nums.size()) {  //防止越界的判断
                helper(nums, i + 1, once, res);
            }
            once.pop_back();
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) {  //为了去掉重复元素
                i++;
            }
        }
    }
};
