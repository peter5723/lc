

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> have_used_num(rows, vector<int>(cols, 0));
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        pair<int, int> direction = std::make_pair(directions[0][0], directions[0][1]);
        int di_index = 0;
        vector<int> result;
        int matrix_size = rows * cols;
        int i = 0;
        int j = 0;
        for (int k = 0; k < matrix_size; k++) {
            result.push_back(matrix[i][j]);
            have_used_num[i][j] = 1;

            //update_next_direction(i, j , direction)
            if (i + direction.first < rows && i + direction.first >= 0 && j + direction.second < cols && j + direction.second >= 0 &&
                have_used_num[i + direction.first][j + direction.second] == 0
                ) {
                    i+=direction.first;
                    j+=direction.second;
                } else {
                    di_index = (di_index + 1) % 4;
                    direction = std::make_pair(directions[di_index][0], directions[di_index][1]);
                    i+=direction.first;
                    j+=direction.second;
                }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.spiralOrder(matrix);
    return 0;
}