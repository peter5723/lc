#include <vector>
#include <iostream>
#include <map>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<char, int>> rows(9);
        vector<map<char, int>> cols(9);
        vector<map<char, int>> boxes(9);
        for (int i = 0;i <= 9;i++) {
            for (int j = 0;j <= 9;j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                rows[i][board[i][j]]++;
                cols[j][board[i][j]]++;
                boxes[j / 3 + i / 3 * 3][board[i][j]]++; // 整除
                if (rows[i][board[i][j]] > 1 || cols[j][board[i][j]] > 1 || boxes[j / 3 + i / 3 * 3][board[i][j]] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
