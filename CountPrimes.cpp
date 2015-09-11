#include <iostream>
#include <vector>
#include <string>
using namespace std;


//这种最简单的解法会超时
/*
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        } else if (n < 3) {
            return 1;   
        }
        int count = 1;
        for(int i = 3; i < n; i += 2) {
            int j;
            for (j = 2; j < i; j++) {
                if (i % j == 0) {  //非质数
                    break;
                }
            }
            if (j >= i) {
                count++;
            }
        }
        return count;
    }
};
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        is_prime[0] = false; // 0不是素数
        is_prime[1] = false; // 1不是素数
        for(int i = 2; i * i < n; i++) {
            if(is_prime[i]) { // 将所有i *(1,...,  i)的数置为false
                for(int j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        int count;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                count++;
            }
        }
        return count;
    }
};
int main(int argc, char** argv) {
    Solution s;
    cout << s.countPrimes(10) << endl;
}
