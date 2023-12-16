#include <bits/stdc++.h>

/*
Problem:
	Paid Staircase

	You are climbing a paid staircase. It takes n steps to reach to the top and you have to
	pay p[i] to step on the i-th stair. Each time you can climb 1 or 2 steps.
	What's the cheapest amount you have to pay to get to the top of the staircase?

Framework for Solving DP Problems:
	1. Define the objective function
		*f(i) is the cheapest amount have to pay to get to the top of the staircase.
	2. Identify base cases
		*f(0) = 0
		*f(1) = p(1)
	3. Write down a recurrence relation for the optimized objective function
		*f(n) = p(n) + min(f(n-1),f(n-2))
	4. What's the order of execution?
		*bottom-up
	5. Where to look for the answer?
		*f(n)
*/
// Time complexity: O(n)
// Space complexity: O(1)
using namespace std;

vector<int> paidStairCases(int n, const int p[]) {
    vector<int> dp(2, 0);
    dp[0] = 0;
    dp[1] = p[1];
    for (int i = 2; i <= n; ++i) {
        dp[i % 2] = p[i] + min(dp[(i - 1) % 2], dp[(i - 2) % 2]);
    }
    return dp[n % 2];
}

int main() {

    int n;
    cin >> n;
    int p[n + 1];
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    cout << paidStairCases(n, p);

    return 0;
}
