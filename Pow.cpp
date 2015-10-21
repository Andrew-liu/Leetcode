//二分法
class Solution {
public:
    double myPow(double x, int n) {
        if(n >= 0) {
            return pow(x, n);
        } else {
            return 1/pow(x, -n);  //为负数的情况
        }
    }
    double pow(double x, int n) {
        if(n == 0) {
            return 1.0;
        }
        double res = pow(x, n / 2);
        if(n % 2 == 0) {   //n为偶数的情况进行还原
            return res * res;
        } else {   // n为奇数的情况进行还原
            return res * res * x; 
        }
    }
};
