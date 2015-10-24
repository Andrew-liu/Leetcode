// 整个是一片1的点, 算作一个岛屿, 只判断上下左右四个方向
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool> > visited(m, vector<bool>(n, false));  // 用于判断当前的位置是否已经访问过
        for(int i = 0; i < m; ++i) {  //遍历所有的节点
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    DFS(grid, visited, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<char> >& grid, vector<vector<bool> >& visited, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) //四种边界情况
            return;
        if(grid[x][y] != '1' || visited[x][y]) 
            return;
        visited[x][y] = true;
        DFS(grid, visited, x - 1, y);
        DFS(grid, visited, x + 1, y);
        DFS(grid, visited, x, y - 1);
        DFS(grid, visited, x, y + 1);
    }
};
