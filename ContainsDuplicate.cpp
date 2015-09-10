#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 复杂度太高, 时间超出限制
 /*
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size() - 1; ++i) {
            int j;
            int pre = nums[i];
            for (j = i + 1; j < nums.size(); ++j) {
                if(nums[j] == pre) {
                    if (j - i <= k) {
                        return true;
                    } 
                } 
                continue;
            }
        }
        return false;
    }
};
*/

//使用字典保存vector所有值的索引 <nums[i], i>, 加速查询
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty() && k == 0) {
            return true;
        }
        unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); ++i) {
            if(dict.find(nums[i]) != dict.end()) {
                if (abs(dict[nums[i]] - i) <= k) {
                    return true;
                }
            }
            dict[nums[i]] = i;
        }
        return false;
    }
};


int main(int argc, char **argv) {
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(1);
    for(auto num : test) {
        cout << "Test" << num << endl;
    }
    Solution s;
    cout << s.containsNearbyDuplicate(test, 5) << endl;
}
