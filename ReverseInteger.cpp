#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool is_neg;
        long long result = 0;
        int last_num = 0;
        if (x >= 0) {
            is_neg = false;
        } else {
            is_neg = true;
        }
        x = abs(x);
        while(x > 0) {
            last_num = x % 10; //找到最后一位数
            result = 10 * result + last_num;
            x = x / 10; //去掉最后一位
        }
        if(result > (long long)INT_MAX || result < (long long)INT_MIN) {  //溢出的时候
            return 0;
        }
        if (is_neg) {
            result = result * (-1);
        }
        return result;
    }
};


int main(int argc, char** argv) {
    Solution s; 
    cout << s.reverse(1534236469) << endl;
}
