/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <vector>
using namespace std;

// 回溯法
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> once;
        vector<vector<int> > res;
        helper(n, k, 1, once, res);
        return res;
    }
    void helper(int n, int k, int level, vector<int>& once, vector<vector<int> >& res) {
        if(k == 0) { //当once的长度等于k时为终止条件
            res.push_back(once);
            return;
        }
        for(int i = level; i <= n - k + 1; ++i) {  //从level开始
            once.push_back(i);
            helper(n, k - 1, i + 1, once, res); //之前的level不再被使用, 所以 + 1
            once.pop_back();  //下次循环时, 又是一个重新开始, once被清空
        }
    }
};

int main(int argc, const char *argv[])
{
    Solution s;
    s.combine(4, 2);
    return 0;
}
