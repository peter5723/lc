
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// 图论，求解连通分量问题，用DFS or BFS 遍历
// 碰到1就说明是新岛屿
// 上下左右四部分将所有的1改成0
class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
    }
};
