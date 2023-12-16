#include <bits/stdc++.h>

using namespace std;

/*
Problem:
	Maximum Profit in a Grid

	A robot is located at the top-left corner of a m x n grid (marked 'S' in the diagram below).
	The robot can only move either down or right at any point in time.
	The robot is trying to reach the bottom-right corner of the grid (marked 'E' in the diagram below).
	Each cell contains a coin the robot can collect.

	What is the maximum profit the robot can accumulate?

	+---+---+---+---+
	| S | 2 | 2 | 1 |
	+---+---+---+---+
	| 3 | 1 | 1 | 1 |
	+---+---+---+---+
	| 4 | 4 | 2 | E |
	+---+---+---+---+

    1. Define the objective function
    f(i,j) is the number of unique paths to get to the (i,j)
    2. Identify base case:
    f(1,1) = 1
    f(2,2) = 2
    3. Transition function:
    f(i,j) = dp(i,j) + max()
    4. Order of the execution:
    Bottom-up
    5. The answer: f(m,n)
*/

// Function to get the maximum profit path
vector<vector<int>> getPath(vector<vector<int>> &dp, int i, int j, vector<vector<int>> path) {
    if (i == 0 && j == 0) {
        path.push_back({i, j});
        return path;
    } else if (i == 0) {
        path = getPath(dp, i, j - 1, path);
    } else if (j == 0) {
        path = getPath(dp, i - 1, j, path);
    } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
            path = getPath(dp, i - 1, j, path);
        } else {
            path = getPath(dp, i, j - 1, path);
        }
    }
    path.push_back({i, j});
    return path;


}

vector<vector<int>> maxProfitPath(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    matrix[0][0] = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = grid[i][j];
            if (i > 0 && j > 0)
                matrix[i][j] += max(matrix[i - 1][j], matrix[i][j - 1]);
            else if (i > 0) {
                matrix[i][j] += matrix[i - 1][j];
            } else if (j > 0) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
    }
    return getPath(matrix, rows - 1, cols - 1, {});
}

int main() {
    vector<vector<int>> path = maxProfitPath({{0, 2, 2, 50},
                                              {3, 1, 1, 100},
                                              {4, 4, 2, 0}});
    cout << "The path is: ";
    for (const auto &p: path) {
        cout << "(" << p[0] << ", " << p[1] << ") ";
    }
    cout << endl;
    return 0;
}