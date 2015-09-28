// 没啥思路的题, 网上搜了一下说是卡特兰数, 略蛋疼
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string once;
        vector<string> res;
        helper(n, 0, 0, once, res);
        return res;
    }
    void helper(int n, int left_num, int right_num, string& once, vector<string>& res) {
        if (left_num == n && right_num == n) {
            res.push_back(once);
            return;
        }
        if (left_num < n) {
            once.push_back('(');
            helper(n, left_num + 1, right_num, once, res);
            once.pop_back();
        }
        if (right_num < left_) {
            once.push_back(')');
            helper(n, left_num, right_num + 1, once, res);
            once.pop_back();
        }
    }
};
