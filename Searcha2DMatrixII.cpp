// 可以从左下或者右上开始找, 一个找规律的题目
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int len = matrix.size(), mlen = matrix[0].size();
        int row = len - 1, col = 0; //取最后一行第一个元素
        while(row >= 0 && col < mlen) {
            if(matrix[row][col] == target) {
                return true;
            } else if(matrix[row][col] > target) { //当前元素大于目标元素, 应该找当前元素上方元素
                row--;
            } else {  //当前元素小于目标元素, 应该找当前元素右边元素
                col++;
            }
        }
        return false;
    }
};
