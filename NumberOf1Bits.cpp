class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res;
        while(n) {
            res += n & 1;  //判断最后一位是不是1
            n >>= 1;  //n右移一位, 即每次循环判断一位是否为1
        }
        return res;
    }
};
