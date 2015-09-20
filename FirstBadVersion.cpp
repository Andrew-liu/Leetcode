// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

//最简单的方法: 直接遍历, 在数字很大的时候会超时
// 第二个想法使用二分法减少判断的次数
class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1 && isBadVersion(1)) {
            return 1;
        }
        int left = 1;
        int right = n;
        //使用left + 1 < right 作为while的条件，这样不会产生死循环和越界的情况
        while(left + 1 < right) { 
            int mid = left + (right - left) / 2;  //不要使用(left + right) / 2 求中间索引
            if (isBadVersion(mid)) {  //坏版本在左边
                right = mid;
            } else {
                left = mid;  //坏版本在右边
            }
        }
        if(isBadVersion(left)) {
            return left;
        }
        return right;
    }

}; 
