class Solution {
public:
    int numSquares(int n) {
        vector<int> temp(n + 1, INT_MAX);
        temp[0] = 0;
        for(int i = 0; i <= n; ++i) {
            for(int j = 1; i + j * j <= n; ++j) {
                temp[i + j * j] = min(temp[i + j * j], temp[i] + 1);
            }
        }
        return temp.back();
    } 
};
/*
基础概念
1. 四平方和定理: 任何一个数都可以表示为四个整数的平方和
2. 如果因为数含有因子4, 可以把是去掉, 不影响结果
3. 一个数除以8余7, 则肯定是由4个完全平方数组成
*/
class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0) {
            n /= 4;
        }
        if(n % 8 == 7) {
            return 4;
        }
        for(int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if(a * a + b * b == n) {
                return !!a + !!b;  //两个正整数时为2, 只有一个正整数时为1
            }
        }
        return 3;
    }
};
