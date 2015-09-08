class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        int new_num = n - 1;  //如果是2的幂, 2^n & (2^n - 1) == 0恒成立
        return ((new_num & n) == 0 ? true : false);
    }
};
