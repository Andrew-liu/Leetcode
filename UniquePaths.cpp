// 深度优先遍历的想法 在维度超过20的时候就会超时, DFS有许多重复的计算
class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths = 0;
        DFS(0, 0, m, n, paths);
        return paths;
    }
    void DFS(int x, int y, int m, int n, int& paths) {
        if(x == m - 1 && y == n - 1) { //找到一条可到终点的路径
            ++paths;
        }
        int offset_x[] = {0, 1};
        int offset_y[] = {1, 0};
        for(int i = 0; i < 2; ++i) {
            int xn = x + offset_x[i];
            int yn = y + offset_y[i];
            if (xn >= m || yn >= n) {  //越界判断, 直接跳过
                continue; 
            }
            DFS(xn, yn, m, n, paths);
        }
    }
};

// 第二种解法, 就是DP的思想
// 只能向下或者向右走, 则dp[i][j] = dp[i-1][j] + dp[i][j-1]
// 当格子只有一行的时候, 到每个格子的走法只有一种, 当格子只有一列时, 每个走法也只有一种
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[i][j] = dp[i -1][j] + dp[i][j - 1];
            }
        }
        return dp[m -1][n - 1];
    }
};
