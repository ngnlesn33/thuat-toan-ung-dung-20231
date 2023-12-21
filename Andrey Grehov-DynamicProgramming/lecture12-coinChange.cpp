#include <bits/stdc++.h>

using namespace std;

/*
Problem:
	Coin change

	Given an unlimited supply of coins of given denominations(1,3,5,10),
	find the total number of ways to make a change of size n.
      1 + 1 + 1 + 1
     /
    4 -- 3 + 1
     \
      1 + 3
--> 3 ways

    1. Define objective function:
    f(i) is the total number of ways to make a change of size i
    2. Identify the base cases:
    f(0) = 1; // count thing
    f(1) = 1;
    f(2) = 1;
    f(3) = 2 = f(2) + f(0);
    3. Transition function
 */
// coinChange(4)

int coinChange(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; ++i) {
        if (i >= 1) dp[i] += dp[i - 1];
        if (i >= 3) dp[i] += dp[i - 3];
        if (i >= 5) dp[i] += dp[i - 5];
        if (i >= 10) dp[i] += dp[i - 10];
    }
    return dp[n];
}

int coinChangeWithDomination(int n, const vector<int>& coins) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n + 1; ++i) {
        for (auto const &coin: coins) {
            if (i - coin >= 0)
                dp[i] += dp[i - coin];
        }
    }
    return dp[n];
}

int main() {
    cout << coinChangeWithDomination(12, {1, 3, 5, 10});
    return 0;
}