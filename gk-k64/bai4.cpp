#include <bits/stdc++.h>

/*
 *  Problem: Fill in the operator
 *  1. Declare the objective fuction: f[i][j] is number of way to achieve the target sum j with the first i numbers.
 *  2. Initialize the base cases: f[0][0] = 1, f[0][j] = 0
 *  3. Find the recurrence relation: f[i][j] = f[i - 1][j - a[i]] + f[i - 1][j + a[i]]
 *  4. Find the order of execution: bottom-up
 *  5. Find the location of the answer: f[n][target]
 *
 */
using namespace std;

int fillInOperator(vector<int> &nums, int targetSum);

int main() {
//    int numOfElements, targetSum;
//    cin >> numOfElements >> targetSum;
    vector<int> nums{3, 2, 7, 5, 2, 3};
//    for (int i = 0; i < numOfElements; ++i) {
//        cin >> nums[i];
//    }
    cout << fillInOperator(nums, 12);
    return 0;
}

int fillInOperator(vector<int> &nums, int targetSum) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (targetSum > sum) return 0; // If targetSum is greater than sum of all elements.
    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
    dp[0][sum] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 2 * sum; ++j) {
            if (j - nums[i - 1] >= 0) dp[i][j] += dp[i - 1][j - nums[i - 1]];
            if (j + nums[i - 1] <= 2 * sum) dp[i][j] += dp[i - 1][j + nums[i - 1]];
        }
    }
    return dp[n][targetSum+sum];
}
