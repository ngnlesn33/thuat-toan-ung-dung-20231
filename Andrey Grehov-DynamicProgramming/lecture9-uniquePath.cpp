#include <bits/stdc++.h>

using namespace std;

/*
Problem:
	Unique Paths

	A robot is located at the top-left corner of a m x n grid (marked 'S' in the diagram below).
	The robot can only move either down or right at any point in time.
	The robot is trying to reach the bottom-right corner of the grid (marked 'E' in the diagram below).

	How many possible unique paths are there?

	+---+---+---+---+
	| S |   |   |   |
	+---+---+---+---+
	|   |   |   |   |
	+---+---+---+---+
	|   |   |   | E |
	+---+---+---+---+

	Above is a 3 x 4 grid. How many possible unique paths are there?

    1. Define the objective function
    f(i,j) is the number of unique paths to get to the (i,j)
    2. Identify base case:
    f(1,1) = 1
    f(2,2) = 2
    3. Transition function:
    f(i,j) = f(i-1,j) + f(i,j-1)
    4. Order of the execution:
    Bottom-up
    5. The answer: f(m,n)
*/

int uniquePath(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));
    matrix[0][0] = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i > 0 && j > 0)
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            else if (i > 0) {
                matrix[i][j] = matrix[i - 1][j];
            } else if (j > 0) {
                matrix[i][j] = matrix[i][j - 1];
            }
        }
    }
    return matrix[rows-1][cols-1];
}

int main() {
    cout << uniquePath(3, 4);
    return 0;
}