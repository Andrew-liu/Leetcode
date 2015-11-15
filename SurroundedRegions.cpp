// 不管四条边上的O, 将中央区域的O变成X, 使用DFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O') { 
                    DFS(board, i, j);  //对四条边上有O的点使用DFS
                }
            }
        }
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '$') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void DFS(vector<vector<char> >& board, int i, int j) {
        if(board[i][j] == 'O') {
            board[i][j] = '$'; 
            if(i > 0 && board[i - 1][j] == 'O') {
                DFS(board, i - 1, j);
            }
            if(j < board[i].size() - 1 && board[i][j + 1] == 'O') {
                DFS(board, i, j + 1);
            }
            if(i < board.size() - 1 && board[i + 1][j] == 'O' ) {
                DFS(board, i + 1, j);
            }
            if(j > 1 && board[i][j - 1] == 'O') {
                DFS(board, i, j - 1);
            }
        }
    }
};
