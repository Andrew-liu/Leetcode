/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        if(word.empty()) {
            return true;
        }
        if(board.empty() || board[0].empty()) {
            return false;
        }
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false)); //用于记录是否当前点已经遍历
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(helper(board, word, 0, i, j , visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char> >& board, string& word, int index, int i, int j, vector<vector<bool> >& visited) {
        if(index == word.size()) {
            return true;  //递归的终结条件
        }
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) {
            return false; //前四个为越界条件, 然后是已经访问过的位置, 最后是字母不匹配
        }
        visited[i][j] = true; //当前字符匹配
        bool res = helper(board, word, index + 1, i - 1, j, visited) ||
                   helper(board, word, index + 1, i + 1, j, visited) ||
                   helper(board, word, index + 1, i, j - 1, visited) ||
                   helper(board, word, index + 1, i, j + 1, visited); //查找上下左右四个位置有没有符合的
        visited[i][j] = false; //查找过后, 回复原状
        return res;
    }
};

int main(int argc, const char *argv[]) {
    
    return 0;
}
