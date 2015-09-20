#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 注意这个题目中数字也被用于判断回文数, 使用头尾两个索引, 来判断是否是相等, 跳过非字符和数字
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) {
            return true;  //空字符串是回文数
        }
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        int start = 0, end = s.size() -1;  //最后一个元素的位置 
        char start_ch, end_ch;
        while(start < end) {
            while(start < end && !isAlpha(s[start])) {  //当前字符不是字母时, 索引加一
                ++start;
            }
            while(start < end && !isAlpha(s[end])) {  //当前字符不是字母时, 索引减一
                --end;
            }
            //全部转换为小写
            if(s[start] != s[end]) {  //两个字符不相等时, 返回false
                return false;
            }
            //当前字符相等
            ++start;
            --end;
        }
        return true;
    }
    bool isAlpha(char ch) { 
        //当为大小写字母时, 返回true
        if (ch >= '0' && ch <= '9') {
            return true;
        }
        if (ch >= 'a' && ch <= 'z') {
            return true;
        }
        return false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    s.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
