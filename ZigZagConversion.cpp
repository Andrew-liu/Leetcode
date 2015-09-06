#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1 || s.size() <= 1) {
            return s;
        }
        string result;
        int len = s.size();
        int size = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < len; j += size) {
                result.push_back(s[j]); //针对垂直位置的字符直接存储
                if (i != 0 && i != numRows - 1) {  //针对非第一行和最后一行, 中间夹着的字符处理
                    int loc = j + size - 2 * i; //通过当前i和j的位置计算中间夹着的字符串
                    if (loc < len) {
                        result.push_back(s[loc]);
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution s;
    string res = s.convert("PAYPALISHIRING", 3);
    cout << res << endl;
}
