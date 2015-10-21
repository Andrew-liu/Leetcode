//这个题的题意是给定一个范围, 如4到6, 写成二进制100, 101, 110 求想与后的结果
//最简单的办法是直接所有的数想与, 复杂度O(n), 会超时
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        while(m != n) {
            res &= m;
            ++m;
        }
        return res;
    }
};

// 第二种方法, 因为都是高位相等, 则将左右边界同时右移, 记录右移的次数, 直到两个数相等, 说明移动结束
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int times = 0;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            ++times;
        }
        return m << times;
    }
};
