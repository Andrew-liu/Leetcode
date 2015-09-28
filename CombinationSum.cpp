#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> once;
        if(candidates.empty()) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, once, res);
        return res;
    }
    void helper(const vector<int>& candidates, int start, int target, vector<int>& once, vector<vector<int> >& res) {
        if(target == 0) {
            res.push_back(once);
            return;
        }
        for(int i = start; i < candidates.size(); ++i) {
            if(i > start && candidates[i - 1] == candidates[i]) {
                continue; //前后两个数相等时, 不在判断
            }
            if(candidates[i] <= target) {
                once.push_back(candidates[i]);
                helper(candidates, i, target - candidates[i], once, res);
                once.pop_back();
            }
        }
    }
};

int main(int argc, char** argv) {
    int nums[] = {2, 3, 6, 7};
    vector<int> test(nums, nums + 4);
    Solution s;
    vector<vector<int> > res = s.combinationSum(test, 7);
    for(auto num : res) {
        for(auto i : num) {
            cout << i << " ";
        }
        cout << endl;
    }
}
