#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


// 超时原因在于, 当不是欢乐数, 第一个while会陷入死循环
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> dict;
        for(int i =0 ; i < 100; i++) {
            dict[i] = (int)pow(i, 2);
        }
        while(n != 1) {
            int temp = 0;
            while(n > 0) {
                temp += dict[n % 10];
                n = n / 10;
            }
            n = temp;
        }
        return n == 1 ? true : false;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        /*
         * 非快乐数前面计算的平方和在后面又回重新出现
         */
        unordered_map<int, int> dict;
        while(n != 1) {
            int temp = 0;
            while(n > 0) {
                temp += (int)pow(n % 10, 2);
                n = n / 10;
            }
            n = temp;
            if(dict.find(temp) == dict.end()) {
                dict[n] = 1;
            } else {  //找到之前出现过, 说明是欢乐数
                return false;
            }
        }
        return n == 1 ? true : false;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.isHappy(19) << endl;
}
