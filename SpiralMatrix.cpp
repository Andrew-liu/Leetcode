class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if(matrix.empty() || matrix[0].empty()) {
            return ret;
        }
        int m = matrix.size(), n = matrix[0].size();
        int nlvl = (min(m,n) + 1) / 2; //表示矩阵要旋转的层数
        for(int i=0; i < nlvl; i++) {
            int row = m - 1 - i;
            int col = n - 1 - i;
            if(row == i) {    // one row remain
                for(int j = i; j <= col; j++)
                    ret.push_back(matrix[i][j]);
            }
            else if(col == i) {   // one col remain
                for(int j = i; j <= row; j++)
                    ret.push_back(matrix[j][i]);
            }
            else {
                for(int j = i; j < col; j++) 
                    ret.push_back(matrix[i][j]);
                for(int j = i; j < row; j++)
                    ret.push_back(matrix[j][col]);
                for(int j = col; j > i; j--)
                    ret.push_back(matrix[row][j]);
                for(int j = row; j > i; j--)
                    ret.push_back(matrix[j][i]);
            }
        }
        return ret;
    }
};
