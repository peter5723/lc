
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 仍然是一看就知道是dfs题目。
//  但是这道题要反过来考虑：我很难判断一个东西被包围了，但是我更好判断哪些东西没有被包围。然后剩下的没有没有包围的就是被包围的我们需要的了。
class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, rows, cols);
            }
            if (board[i][cols - 1] == 'O') {
                dfs(board, i, cols-1, rows, cols);
            }
        }
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, rows, cols);
            }
            if (board[rows - 1][j] == 'O') {
                dfs(board, rows-1, j, rows, cols);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, int rows, int cols) {
        //注意访问过的也要标注防止重复访问
        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] == 'X' || board[i][j] == '#') {
            return;
        }
        board[i][j] = '#';
        dfs(board, i + 1, j, rows, cols);
        dfs(board, i - 1, j, rows, cols);
        dfs(board, i, j + 1, rows, cols);
        dfs(board, i, j - 1, rows, cols);
    }
};