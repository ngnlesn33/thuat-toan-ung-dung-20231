#include <bits/stdc++.h>

using namespace std;

/*
Problem:
	Paint Fence With Two Colors

	There is a fence with n posts, each post can be painted with either green or blue color.
	You have to paint all the posts such that no more than two adjacent fence posts have the same color.
	Return the total number of ways you can paint the fence.

    1. Define the objective function
    f(i,j) is the number of ways to paint i fences that end with color j(0-green,1-blue)
    2. Identify the base cases:
    f(0,0), f(0,1) = 0
    f(1,0), f(1,1) = 1
    f(2,0), f(2,1) = 2
    3. Write down a recurrence relation for the optimized objective function
    f(i,j) = f(i-1,1-j) + f(i-2,1-j);
    // 3 6
    // 4 10
    // 5 16
*/

int numWays(int n) {
    vector<vector<int>> dp(n + 1, (vector<int>(2, 0)));
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 2;
    dp[2][1] = 2;

    for (int i = 3; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            dp[i][j] = dp[i - 1][1 - j] + dp[i - 2][1 - j];
        }
    }
    return dp[n][0] + dp[n][1];
}

int main() {
    int n;
    cin >> n;
    cout << numWays(n);
    return 0;
}