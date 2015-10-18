/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */

// 暴力遍历方案, 妥妥的超时了
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int offset = INT_MAX;
        int min = target, sum = 0;
        for(int i = 0; i < nums.size() - 2; ++i) {
            for(int j = i + 1; j < nums.size() - 1; ++j) {
                for(int k = j + 1; k < nums.size(); ++k) {
                    sum = nums[i] + nums[j] + nums[k];
                    cout << nums[i] << nums[j] << nums[k] << " " << sum << endl;
                    int no = abs(target - sum);
                    if(offset > no) {
                        offset = no;
                        min = sum;
                    }
                    cout << offset << " " << min << endl;
                }
            }
        }
        return min;
    }
};

// 使用对撞指针计算 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_offset = INT_MAX;  //存储最小距离
        for(int i = 0; i < nums.size() - 2; ++i) {
            int second = i + 1, third = nums.size() - 1;
            while(second < third) {
                int offset = nums[i] + nums[second] + nums[third] - target; //计算相差的距离
                if(abs(offset) < abs(min_offset)) {
                    min_offset = offset;
                }
                if(offset == 0) {  //sum与target完全相等
                    break;
                } else if(offset < 0) {
                    second++;
                } else {
                    third--;
                }
            }
        }
        return target + min_offset;
    }
};
int main(int argc, const char *argv[])
{
    int a[] = {-1, 2, 1, -4};
    vector<int> test(a, a + 4);
    Solution s;
    cout << s.threeSumClosest(test, 1) << endl;
    return 0;
}
