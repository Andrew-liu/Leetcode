// 使用深度优先遍历, 遇到大数据又超时了, 我真日了狗了
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int paths = 0;
        DFS(obstacleGrid, 0, 0, obstacleGrid.size(), obstacleGrid[0].size(), paths);
        return paths;
    }
    void DFS(vector<vector<int> >& grid, int x1, int y1, int m, int n, int& paths) {
        if(x1 == m - 1 && y1 == n - 1) {
            ++paths;
        }
        int offset_x[] = {0, 1};
        int offset_y[] = {1, 0};
        for(int i = 0; i < 2; ++i) {
            int x = x1 + offset_x[i];
            int y = y1 + offset_y[i];
            if(x >= m || y >= n || grid[x][y] == 1) {
                continue;
            }
            DFS(grid, x, y, m, n, paths);
        }
    }
};
// 动态规划方案
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        dp[0][0] = (obstacleGrid[0][0] == 0 ? 1 : 0);  //初始化
        for(int i = 1; i < m; i++) {  
            dp[i][0] = ((dp[i - 1][0] == 1 && obstacleGrid[i][0] == 0) ? 1 : 0);
        }
        for(int j = 1; j < n; j++) {
            dp[0][j] = ((dp[0][j - 1] == 1 && obstacleGrid[0][j] == 0) ? 1 : 0);
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
