class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        int m = matrix.size(), n = matrix[0].size();
        bool zero_row = false, zero_col = false;
        for(int i = 0; i < n; ++i) {
            if(matrix[0][i] == 0) {
                zero_row = true; //第一行应该清零
                break;
            }
        }
        for(int i = 0; i < m; ++i) {
            if(matrix[i][0] == 0) {
                zero_col = true; //第一列应该清零
                break;
            }
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 0) { //某行某列元素为0时, 将改行第一个元素, 和该列第一个元素变0
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) { 
                    matrix[i][j] = 0;
                }
            }
        }
        if(zero_row) {
            matrix[0] = vector<int>(n, 0);
        }
        if(zero_col) {
            for(int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
