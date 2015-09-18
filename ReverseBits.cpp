#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//考虑位移操作
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1 == 1) { //当前为1, 
                res = (res << 1) | 1;  //左移一位, 然后或上1
            } else {
                res = res << 1;  //否则为0时, 直接左移一位就行了
            }
            n = n >> 1;
        }
        return res;
    }
};


int main(int argc, char** argv) {
    Solution s;
    cout << s.reverseBits(1) << endl;
}
