#include <iostream>
#include <bitset>
#include <string>
using namespace std;

//思路: 从右向左遍历字符串, 以长的字符串为基准, 超出长度则补零, 主要从字符转化为数字和数字转字符的方法
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int len_a = a.size();
        int len_b = b.size();
        int overflow = 0; //记录进位情况
        int len = len_a > len_b ? len_a : len_b; //找到较长一个字符串的长度
        for(int i = 0; i < len; ++i) {
            char right_a = i < len_a ? a[len_a - i - 1] : '0'; //从字符串的右边取字符
            char right_b = i < len_b ? b[len_b - i - 1] : '0'; //从字符串的哟边取每一位字符
            int cur = right_a -'0' + (right_b - '0') + overflow; //两个字符转换成整数相加并加上进位
            overflow = cur / 2; //如果相加等于2, 则产生进位
            if(cur % 2 == 0) {
                res = "0" + res;
            } else {
                res = "1" + res;
            }  //将当前为数转换为字符后, 插入字符串的首位
        }
        if(overflow) { //最后产生了进位
            res = "1" + res;
        }
        return res;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int max_size = max(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for (int i = 0; i < max_size; ++i) {
            int one = a.size() > i ? a[i] - '0' : 0;
            int two = b.size() > i ? b[i] - '0' : 0;
            int cur = (one + two + carry) % 2;
            carry = (one + two + carry) / 2;
            result.insert(result.begin(), cur + '0'); // 注意需要在首部插入char
        }
        if (carry == 1) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    string a("111");
    string b("1");
    s.addBinary(a, b);
    return 0;
}
