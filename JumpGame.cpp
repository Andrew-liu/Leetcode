/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        for(int i = 1; i < len; ++i) {
            dp[i] = max(nums[i - 1], dp[i - 1]) - 1;
            cout << "dp[" << i << "] = " << dp[i] << endl;
            if(dp[i] < 0) {
                return false;
            }
        }
        return dp[len - 1] >= 0;
    }
};

int main(int argc, const char *argv[])
{
    int a[] = {1, 0, 2};
    vector<int> test(a, a + 3);
    Solution s;
    cout << s.canJump(test) << endl;
    return 0;
}
