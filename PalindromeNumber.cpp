class Solution {
public:
    bool isPalindrome(int x) {
        int sign = 1, last = 0, first = 0;
        if (x < 0) {
            return false;
        }
        int div = 1;
        // 获得可以得到最高位的除数
        while(x / div >= 10) {
            div *= 10;
        }
        while(x > 0) {
            last = x % 10;  //得到最低位
            first = x / div; //得到最高位
            if (last != first) {
                return false;
            }
            //去掉最高位和最低位
            x %= div;
            x /= 10; 
            div /= 100; //x减少了两位
        }
        return true;
    }
};
