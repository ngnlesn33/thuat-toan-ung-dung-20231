#include <bits/stdc++.h>

using namespace std;

/*
 * Problem: Given n is numbers of element in array and an array of integers, find the sum of subsequence that the sum is
 * largest and not any number in subsequence is next to each other.
 *  Input: 5 1 2 3 4 5
 *  Output: 11
 *  1. Declare objective function: f[i] is the largest sum of subsequence that ending in i and not any number in
 *  subsequence is next to each other.
 *  2. Initialize the base cases: f[0] = a[0], f[1] = max(a[0], a[1])
 *  3. Find the recurrence relation: f[i] = max(f[i - 1], f[i - 2] + a[i])
 *  4. Find the order of execution: bottom-up
 *  5. Find the location of the answer: f[n]
 */

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    for (int i = 2; i < n + 1; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }
    cout << dp[n];
}