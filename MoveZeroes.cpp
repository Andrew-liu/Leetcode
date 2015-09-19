#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 思路: 当元素等于0时, 则后一个元素覆盖他
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int offset = 0; 
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[offset++] = nums[i];
            }
        }
        while(offset != len) {  //或者小于号
            nums[offset++] = 0;
        }
    }
};

int main(int argc, char** argv) {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    Solution s;
    s.moveZeroes(nums);
    for(auto num : nums) {
        cout << num << endl;
    }
    return 0;
}
