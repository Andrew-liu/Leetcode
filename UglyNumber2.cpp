/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <string>
using namespace std;

// 暴力枚举的方法: 会超时
class Solution {
public:
    int nthUglyNumber(int n) {
        int num = 1;
        while(n != 0) {
            for(int i = num; i < INT_MAX; ++i) {
                if(isUgly(i)) {
                    //cout << i << " " << endl;
                    num = ++i;
                    n--;
                    break;
                }
            }
        }
        return num;
    }
    bool isUgly(int num) {
        if (num == 1) {
            return true;
        }
        while(num % 2 == 0) {
            num /= 2 ;
        }
        while(num % 3 == 0) {
            num /= 3;
        }
        while(num % 5 == 0) {
            num /= 5;
        }
        return (num == 1);
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while(res.size() < n) {
            int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
            int m = min(m2, min(m3, m5));
            if(m == m2) {
                ++i2;
            }
            if(m == m3) {
                ++i3;
            }
            if(m == m5) {
                ++i5;
            }
            res.push_back(m);
        }
        return res.back();
    }
};

int main(int argc, const char *argv[])
{
    Solution s;
    cout << s.nthUglyNumber(10) << endl;
    return 0;
}
