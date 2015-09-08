#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 这题感觉思路非常乱, 不知道怎么AC, 下次重做吧.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() <= 0) {
            return res;
        }
        if (nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int counter = 0;
        int first = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == (nums[i - 1] + 1)) {
                if(i == nums.size() - 1) {
                    res.push_back(to_string(first) + "->" + to_string(nums[i]));
                }
                if(counter == 0) {
                    first = nums[i - 1]; 
                }
                counter++;
                continue;
            } else {
                string temp;
                if (first == nums[i- 1]) {
                    temp = to_string(first);
                } else {
                    temp = to_string(first) + "->" + to_string(nums[i - 1]);
                }
                first = nums[i];
                res.push_back(temp);
                counter = 0;
                if (i == nums.size() - 1) {
                    res.push_back(to_string(nums[i]));
                }
            }
        }
        return res;
        
    }
};

int main(int argc, char **argv) {
    vector<int> start;
    start.push_back(0);
    start.push_back(1);
    start.push_back(2);
    start.push_back(4);
    Solution s;
    vector<string> new_data(s.summaryRanges(start));
    for(auto str : new_data) {
        cout << str << endl;
    }
}
