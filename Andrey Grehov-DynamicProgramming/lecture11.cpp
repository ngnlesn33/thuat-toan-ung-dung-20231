#include <bits/stdc++.h>


using namespace std;

int fibTopDownHelper(int n, unordered_map<int, int> &map);

// Regular recursion
// Time complexity: O(n)
int fib(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

// Top-down dynamic programming (recursion + memoization(aka caching))
int fibTopDown(int n) {
    unordered_map<int, int> memo;
    return fibTopDownHelper(n, memo);
}

int fibTopDownHelper(int n, unordered_map<int, int> &memo) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    memo[n] = fibTopDownHelper(n - 1, memo) + fibTopDownHelper(n - 2, memo);
    return memo[n];
}

// this is a bottom-up dynamic programming (forward dynamic programming)
//
// f(i-1)
//      \
//       >-------> f(i)
//      /
// f(i-2)
//
int fibBottomUpDPForward(int n) {
    // Time complexity: O(n)
    // Space complexity: O(n) -> (0,5 , 0,8) ms
    // Space complexity: O(1) -> 0.45 ms
    if (n == 0) return 0;
    if (n <= 2) return 1;
    vector<int> dp(2, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i % 2] = dp[(i - 1) % 2] + dp[(i - 2) % 2];
    }
    return dp[n % 2];
}

// this is a bottom-up dynamic programming (backward dynamic programming)
//
//   -----> f(i+2)
//   |
// f(i)
//   |
//   -----> f(i+1)
//
int fibBottomUpDPBackward(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    vector<int> dp(n + 2, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i + 1] += dp[i];
        dp[i + 2] += dp[i];
    }
    return dp[n];
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
//    cout << fibTopDown(1000);
//    cout << fib(40);
//    cout << fibBottomUpDPForward(1000);
    cout << fibBottomUpDPBackward(1000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    cout << endl;
    std::cout << "Elapsed time: " << elapsed.count() << " ms\n";

    return 0;
}