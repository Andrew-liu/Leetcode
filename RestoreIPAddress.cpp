/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 回溯法
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size() > 15) {  //3 * 4个数字 + 3个点 = 15
            return res;
        }
        string once;
        helper(s, 4, once, res); //IP由4段数字组成
        return res;
    }
    void helper(string s, int k, string once, vector<string>& res) {
        if(k == 0 && s.empty()) { //k表示找到4个数 且 此时字符串为空
            res.push_back(once);
            return;
        }
        for(int i = 1; i <= 3; ++i) { // 每个数最少1位, 最多三位
            if(i <= s.size() && isValid(s.substr(0, i))) {
                if(k == 1) { // 4个数现在只差一个数
                    helper(s.substr(i), k - 1, once + s.substr(0, i), res);
                } else { //不是最后一个数时, 要加上.
                    helper(s.substr(i), k - 1, once + s.substr(0, i) + ".", res);
                }
            }
        }
    }
    bool isValid(string s) {
        std::cout << s << std::endl;
        if(s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) {  //最后一个判断条件是因为可能出现 012这种情况
            return false;
        }
        int res = atoi(s.c_str());
        return res <= 255 && res >= 0;
    }
};

int main(int argc, const char *argv[]) {
    string test = "0000";
    Solution s;
    s.restoreIpAddresses(test);
    return 0;
}
