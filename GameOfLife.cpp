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
    void gameOfLife(vector<vector<int> >& board) {
        if(board.size() == 0 || board[0].size() == 0) {
            return;
        }
        int x_offset[] = {1, 1, 1, 0, 0, -1, -1, -1};  //通过两个数据的辅助, 来访问周边八个元素
        int y_offset[] = {1, 0, -1, 1, -1, 1, 0, -1};
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int live = 0;  //存储当前元素的周边存活数
                for(int k = 0; k < 8; ++k) {
                    int x_index = i + x_offset[k];
                    int y_index = j + y_offset[k];
                    if(x_index < 0 || y_index < 0 || x_index >= m || y_index >= n) { //越界处理
                        continue;
                    } else {
                        live += (board[x_index][y_index] & 1);  //获取最后一位的数值, 表示死或者活
                    }
                } //获得周边八个元素的存活状态
                cout << live << endl;
                if((live + board[i][j]) == 3 || live == 3) {  //表示三种情况, 我活着且周围有2个活着, 我死了且中卫有3个或者, 我活着周围有三个活着
                    board[i][j] |= 2;  // 2的二进制为10, 所有将死活状态设置为第二位
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                board[i][j] >>= 1;  //右移一位, 回复高位的新状态
            }
        }
    }
};

int main(int argc, char** argv) {
    vector<vector<int> > test;
    int a[] = {1, 1};
    int b[] = {1, 0};
    test.push_back(vector<int>(a, a + 2));
    test.push_back(vector<int>(b, b + 2));
    Solution s;
    s.gameOfLife(test);
    return 0;
}
