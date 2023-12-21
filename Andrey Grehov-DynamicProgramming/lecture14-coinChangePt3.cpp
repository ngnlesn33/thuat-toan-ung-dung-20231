#include <bits/stdc++.h>

using namespace std;

/*
Problem:
	Coin change

	Given an unlimited supply of coins of given denominations,
	find the total number of ways to make a change of size n, by
	using an even number of coins.
    1 - even, 0 - odd
	// 1, 3, 5, 10
	1. Declare objective function:
    f(i,1) is total number of ways to make a change of size n by using an even number of coin
    2. Define the base cacses:
    f(0,0) = 0;
    f(0,1) = 1;
//    f(1,0) = 1;
//    f(1,1) = 0;
    f(i,1) = f(i-1,0) + f(i-3,0) + ...
*/

int coinChange(int n, const vector<int>& coins) {
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 1;

    for (int i = 1; i < n + 1; ++i) {
        for (auto const &coin: coins) {
            if (i - coin < 0)
                continue;
            dp[i][0] += dp[i - coin][1];
            dp[i][1] += dp[i - coin][0];
        }
    }
    return dp[n][1];
}

int main() {
    cout << coinChange(4, {1, 3, 5, 10});
    return 0;
}