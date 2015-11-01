// 题意: 在一个二维矩阵中, 找到全一的方阵并且面积最大
// 暴力遍历法
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            vector<int> v(matrix[i].size(), 0);
            for(int j = i; j < matrix.size(); ++j) {
                for(int k = 0; k < matrix[j].size(); ++k) {
                    if(matrix[j][k] == '1') {
                        ++v[k];
                    }
                }
                res = max(res, getArea(v, j - i + 1));
            }
        }
        return res;
    }
    int getArea(vector<int>& v, int k) {
        if(v.size() < k) {
            return 0;
        }
        int count = 0;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i] != k) {
                count = 0;
            } else {
                ++count;
            }
            if(count == k) {
                return k * k;
            }
        }
        return 0;
    }
};
