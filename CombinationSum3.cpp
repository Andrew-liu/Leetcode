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
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> once;
        helper(1, k, n, once, res);
        return res;
    }
    void helper(int start, int k, int n, vector<int>& once, vector<vector<int> >& res) {
        if(once.size() == k && n == 0) {
            res.push_back(once);
            return;
        }
        for(int i = start; i <= 9 && i <= n; ++i) {
            once.push_back(i);
            helper(i + 1, k, n - i, once, res);
            once.pop_back();
        }
    }
};
int main(int argc, const char *argv[])
{
    Solution s;
    vector<vector<int> > res = s.combinationSum3(3, 9);
    for(auto once : res) {
        for(auto num : once) {
            cout << num << endl;
        }
    }
    return 0;
}
