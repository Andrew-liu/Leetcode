/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <string>
using namespace std;

// 找到所有可能的中心向两边扫, 一共有2 * n - 1(字符作为中心有n个, 间隙作为中心有n - 1)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1) {
            return s;
        }
        int start = 0, left = 0, right = 0, len = 0;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(s[i] == s[i + 1]) {
                left = i;
                right = i + 1;
                palindrome(s, left, right, start, len);
            }
            left = right = i;
            palindrome(s, left, right, start, len);
        }
        if(len == 0) {
            len = s.size();
        }
        return s.substr(start, len);
    }
    void palindrome(string& s, int left, int right, int& start, int& len) {
        int step = 1;
        while((left - step) >= 0 && (right + step) < s.size()) {
            if(s[left - step] != s[right + step]) {  //不相等时
                break;
            }
            ++step; //相等则分别向左右走一步
        }
        int wide = right - left + 2 * step -1; //回文数的长度
        if(len < wide) {
            len = wide;
            start = left - step + 1;
        }
    }
};
int main(int argc, const char *argv[])
{
    string test = "aba";
    Solution s;
    cout << s.longestPalindrome(test) << endl;
    return 0;
}
