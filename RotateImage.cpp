// 两步
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 沿对角线翻转
        int len = matrix.size();
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len - i; j++) {
                swap(matrix[i][j], matrix[len- 1 - j][len - 1 - i]);
            }
        }
        //上下翻转
        for(int i = 0; i < len / 2; ++i) {
            for(int j = 0; j < len; j++) {
                swap(matrix[i][j], matrix[len - 1 - i][j]);  //上下翻转y轴不变
            }
        }
    }
};
