// 和上一题仅有的区别是不重复查找元素
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> once;
        if(candidates.size() == 0) {
            return res;
        }
        sort(candidates.begin(), candidates.end()); //注意要排序, 才能输出从小到大的顺序
        helper(candidates, 0, target, once, res);
        return res;
    }
    void helper(vector<int>& candidates, int start, int target, vector<int>& once, vector<vector<int> >& res) {
        if(target == 0) {
            res.push_back(once);
            return;
        }
        for(int i = start; i < candidates.size(); ++i) {
            if(i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if(candidates[i] <= target) {
                once.push_back(candidates[i]);
                helper(candidates, i + 1, target - candidates[i], once, res);
                once.pop_back();
            }
        }
    }
};
