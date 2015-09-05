class Solution {
public:
    int trailingZeroes(int n) {
        int base = 5;
        int zeros = 0;
        while (n >= base) {
            zeros = n / 5; //单5在阶乘中的个数
            n /= 5; //多个5在阶乘中的个数
        }
        return zeros;
    }
};
