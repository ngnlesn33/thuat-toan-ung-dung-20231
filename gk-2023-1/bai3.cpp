#include <bits/stdc++.h>

using namespace std;

/*
Problem:
	Maximum Profit in a Grid

	A robot is located at the top-left corner of a m x n grid
	The robot can only move either down or right or cross at any point in time.
	The robot is trying to reach the bottom-right corner of the grid (marked 'E' in the diagram below).
	Each cell contains a coin the robot can collect. If the a cell is 0, the robot can not go through that cell.
    Print -1 if robot cannot reach the bottom-right corner of the grid.
	What is the minimum profit the robot can accumulate?

    Input:
    5 6
    1   2 0 5 1 3
    5  -9 2 0 1 3
    1   4 1 5 7 4
    -60 1 0 0 0 0
    6   7 0 5 4 3
    Output: -1
    1. Define the objective function
    f(i,j) is the minimum profit to get to the (i,j)
    2. Identify base case:
    f(1,1) = grid[1][1]
    3. Transition function:
    f(i,j) = min(f(i-1,j), f(i,j-1), f(i-1,j-1))
    4. Order of the execution:
    Bottom-up
    5. The answer: f(m,n)

*/

int minProfit(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[1][1] = grid[0][0];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            if (grid[i - 1][j - 1] == 0) continue;
            int minPrev = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            if (minPrev != INT_MAX) dp[i][j] = minPrev + grid[i - 1][j - 1];
        }
    }
    return (dp[m][n] == INT_MAX) ? -1 : dp[m][n];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << minProfit(grid);
    return 0;
}


