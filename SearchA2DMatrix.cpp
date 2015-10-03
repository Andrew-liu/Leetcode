//最初想法: 找到对应行然后做二分查找
//对每一行vector采用二分查找, 这个解法超时了
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len = matrix.size();
        if(len == 0) {
            return false;
        }
        int mlen = matrix[0].size();
        if(mlen == 0) {
            return false;
        }
        for(int i = 0; i < len; ++i) {
            vector<int> temp = matrix[i];
            int last = temp[mlen - 1];
            if(last < target) {
                continue;
            } else if (last == target) {
                return true;
            } else {
                int beg = 0;
                int end = mlen - 1;
                int mid;
                while(beg <= end) {
                    mid = beg + (end - beg) / 2;
                    if(temp[mid] == target) {
                        return true;
                    } else if(temp[mid] > target) {
                        end = mid - 1;
                    } else {
                        end = mid + 1;
                    }
                }
                return false;
            }
        }
        return false;
    }

};
//O(n)时间复杂度
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len = matrix.size();
        if(len == 0) {
            return false;
        }
        int mlen = matrix[0].size();
        if(mlen == 0) {
            return false;
        }
        int col = 0, row = len - 1;
        while(row >= 0 && col < mlen) {
            if(target < matrix[row][col]) {  //从最后一行开始比较
                row--;
            } else if(target > matrix[row][col]) {
                col++;
            } else {
                return true;
            }
        }
        return false;
    }
};
