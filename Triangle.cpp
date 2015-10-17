class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if(rows == 0) {
            return 0;
        }
        vector<int> dp(triangle[rows -1].size());  //最后一行的元素个数, 初始化dp数组
        for(int i = rows - 1; i >= 0; --i) {
            int cols = triangle[i].size();
            for(int j = 0; j < cols; ++j) { //遍历当前行的每个元素
                if(i == rows - 1) {  //最后一行特殊处理, 用最后一行的元素来初始化dp数组
                    dp[j] = triangle[i][j];
                    continue;
                }
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]; // 自底向上的查找最小值
            }
        }
        return dp[0];
    }
};
