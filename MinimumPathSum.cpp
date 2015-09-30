#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        vector<vector<int> > min_mat(row + 1, vector<int>(col + 1, INT_MAX));  // 增加一行一列用于处理边界情况
        //min[i][j]表示从左上角到grid[i-1][j-1]的最小路径和
        min_mat[0][1] = 0; //初始化最初两个动态方式的元素
        min_mat[1][0] = 0;
        for(int i = 1; i <= row; ++i) {
            for(int j = 1; j <= col; ++j) {
                min_mat[i][j] = grid[i - 1][j - 1] + min(min_mat[i-1][j], min_mat[i][j-1]);
            }
        }
        return min_mat[row][col];
    }
};

int main(int argc, char** argv) {
    vector<vector<int> > test(1, vector<int>(1, 0));
    Solution s;
    cout << s.minPathSum(test) << endl;
}
