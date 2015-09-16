#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {  //nums 为0时,
            return 0;
        }
        int offset = 1;  //第一个元素必然不是相等, 所以偏移从1开始
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[i - 1]) {
                nums[offset++] = nums[i];
            }
        }
        return offset;
    }
};

int main(int argc, char** argv) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    int offset = s.removeDuplicates(nums);
    for(auto num : nums) {
        cout << num << ' ';
    }
    cout << endl;
    cout << offset << endl;
}


