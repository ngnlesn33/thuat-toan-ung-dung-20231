#include <bits/stdc++.h>

using namespace std;

/*
 * Problems:
 * 1. Define objective function
 * Solution is unique
 *  f(i,t) is the total number of ways to make a change of size i when the last coin is less than or equal to t (not increasing)
 * 2. Identify the base cases:
 *  f(0,t) = 1
 *  f(i,0) = 0 f(i,1) = 1
 *  f(i,2) = f(i-2,2) + f(i-1,1)
 *  3. Transition function:
 *  for coin in coins:
 *      f(i,t) += f(i-coin, coin)
 *  4. Order of execution: Bottom-up
 *  5. The answer: f(n, t)
 */
int coinChangeUniqueWays(int n, vector<int> coins) {
    vector<vector<int>> dp(n + 1, vector<int>(coins.size()+1, 0));

    for (int i = 0; i < coins.size(); i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < coins.size(); j++) {
            for (int k = 0; k <= j; k++) {
                if (i - coins[k] >= 0) {
                    dp[i][j] += dp[i - coins[k]][k];
                }
            }
        }
    }
    return dp[n][coins.size() - 1];
}

int main() {
    cout << coinChangeUniqueWays(75, {1, 2, 3, 5});
    return 0;

}