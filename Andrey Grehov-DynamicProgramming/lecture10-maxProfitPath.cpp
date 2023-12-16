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

    // Frame work to reconstruct the path
    path = []
    for curr = best_lst_state, curr > 0, curr = from[curr]
        path.push(curr)
    return path.reverse()
*/

vector<vector<int>> maxProfitPath(vector<vector<int>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<pair<int, int>>> from(rows, vector<pair<int, int>>(cols, {-1, -1}));
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    matrix[0][0] = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = grid[i][j];
            if (i > 0 && j > 0) {
                matrix[i][j] += max(matrix[i - 1][j], matrix[i][j - 1]);
                if (matrix[i - 1][j] > matrix[i][j - 1])
                    from[i][j] = {i - 1, j};
                else
                    from[i][j] = {i, j - 1};
            } else if (i > 0) {
                matrix[i][j] += matrix[i - 1][j];
                from[i][j] = {i - 1, j};
            } else if (j > 0) {
                matrix[i][j] += matrix[i][j - 1];
                from[i][j] = {i, j - 1};
            }
        }
    }

    vector<vector<int>> path{};
    for (pair<int, int> curr{rows - 1, cols - 1}; curr.first >= 0 && curr.second >= 0; curr = from[curr.first][curr.second]) {
        path.push_back({curr.first, curr.second});
    }
    reverse(path.begin(), path.end());
    return path;
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