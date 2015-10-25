//摩尔投票法, 初始选取一个候选元素和一个计数器, 当计算器等于0时, 更新候选元素为当前元素, 并将计算器置1
// 当候选元素等于当前元素时, 计数器加一, 否则计算器减一
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int m = 0, n = 0, cm = 0, cn = 0;
        for(auto &a : nums) {
            if(a == m) {
                ++cm;
            } else if(a == n) {
                ++cn;
            } else if(cm == 0) {
                m = a;
                cm = 1;
            } else if(cn == 0) {
                n = a;
                cn = 1;
            } else {
                --cm;
                --cn;
            }
        }
        cm = cn = 0;
        for(auto &a : nums) {
            if(a == m) {
                ++cm;
            } else if (a == n) {
                ++cn;
            }
        }
        if(cm > nums.size() / 3) {
            res.push_back(m);
        }
        if(cn > nums.size() / 3) {
            res.push_back(n);
        }
        return res;
    }
};
