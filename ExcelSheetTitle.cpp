#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        // 想象成26进制
        string res;
        while(n > 0) {
            n--;  //使下面的计算方便
            char ch = (char) (n % 26 + 'A'); // 数字转换为字母
            n /= 26;
            res = ch + res;
        }
        return res;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.convertToTitle(28) << endl;
}
