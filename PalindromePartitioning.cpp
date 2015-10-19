// 对每一步找到的元素index, 都判断0到index是不是回文字符串
class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> once;
        helper(s, 0, once, res);
        return res;
    }
    void helper(string& s, int start, vector<string> once, vector<vector<string> >& res) {
        if(start == s.size()) {  //每次遍历到最后则停止
            res.push_back(once);
            return;
        }
        for(int i = start; i < s.size(); ++i) {
            if(isPalindrome(s, start, i)) {  //判断首位到当前索引是不是回文数
                once.push_back(s.substr(start, i - start + 1)); // 左闭右开区间
                helper(s, i + 1, once, res);
                once.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) { //非回文数
                return false;
            }
        }
        return true;
    }
};
