#include <bits/stdc++.h>

using namespace std;

/*
Problem:
	Coin change

	Given an unlimited supply of coins of given denominations,
	find the total number of ways to make a change of size n, by
	using exactly t coins.

	f(i,t) = f(i-1, t-1) + f(i-2, t-1) + f(i-3, t-1) + f(i-5, t-1)

    1. Define the object function:
        f(i,t) is the total number of ways to make a change of size i by using exactly t coins.
    2. Identify the base cases:
        f(0,i) = 0; f(i,0) = 0
        f(0,0) = 1;
        else = 0
    3. Transition function
        f(i,t) = (for coin in coins){return f(i,t) += f(i-coin,t-1)}
    4. Order of execution: Bottom-up
    5. The answer: f(n,t)
*/

int coinChangeExactlyTCoin(int n, int t, const vector<int> &coins) {
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < t + 1; ++j) {
            if (i > 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }
            for (auto const &coin: coins) {
                if (i - coin >= 0) {
                    dp[i][j] += dp[i - coin][j - 1];
                }
            }
        }
    }
    return dp[n][t];
}

/*
 1. Define objective function
    f(i,t) is the number of ways to make a change of size i with no more than t coin
2. Define the base case:
    f(0,0) = 1;
    f(i,0) = 0;
    f(0,i) = 1;


 */
int coinChangeNoMoreThanTCoin(int n, int t, const vector<int> &coins) {
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < t + 1; ++j) {
            if (i > 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j > 0) {
                dp[i][j] = 1;
                continue;
            }
            for (auto const &coin: coins) {
                if (i - coin >= 0) {
                    dp[i][j] += dp[i - coin][j - 1];
                }
            }
        }
    }
    return dp[n][t];
}

int main() {
    cout << coinChangeExactlyTCoin(0, 1, {1, 2, 3, 5});
    return 0;
}