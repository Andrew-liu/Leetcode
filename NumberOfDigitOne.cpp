// 题意: 从1 - n 这n个数中, 数的十进制所有1出现的个数(111这个数1出现了三次)
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0, a = 1, b = 1;
        while(n > 0) {
            res += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};
