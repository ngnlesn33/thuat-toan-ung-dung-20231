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
int changeCoin(int n, const vector<int> &coins) {
    vector<vector<int>> dp(n + 1, vector<int>(coins.size() + 1, 0));
    for (auto const &t: coins)
        dp[0][t] = 1;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < ; ++j) {
            
        } 
    }
}

int main() {
    return 0;

}