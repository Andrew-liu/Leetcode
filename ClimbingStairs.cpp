// 斐波那契数的递归解法, 显然会超时
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// 斐波那契数的非递归解法
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int front = 1, end = 2, res = 0;  //前一个n-2, 后一个数n-1, n
        for(int i = 3; i <= n; ++i) {
            res = front + end;
            front = end;
            end = res;
        }
        return res;
    }
};
