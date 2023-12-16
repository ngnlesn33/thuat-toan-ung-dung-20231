#include <bits/stdc++.h>

using namespace std;

/*
Problem:
	Paid Staircase II

	You are climbing a paid staircase. It takes n steps to reach to the top, and you have to
	pay p[i] to step on the i-th stair. Each time you can climb 1 or 2 steps.
	Return the cheapest path to the top of the staircase.

Template to reconstruct the path
================================

	path = []
	for curr = best_last_state; curr exists; curr = from[curr] {
		path.push(curr)
	}
	return path.reverse()

*/

// Time complexity: O(n)
// Space complexity: O(n)


vector<int> paidStairCases(int n, const int p[]) {
    vector<int> dp(n + 1, 0);
    vector<int> from(n + 1, 0);
    dp[0] = 0;
    dp[1] = p[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = p[i] + min(dp[i - 1], dp[i - 2]);
        if (dp[i - 1] > dp[i - 2]) {
            from[i] = i - 2;
        } else {
            from[i] = i - 1;
        }
    }
    vector<int> path;
    for (int curr = n; curr > 0; curr = from[curr]) {
        path.push_back(curr);
    }
    path.push_back(0);
    return path;
}

int main() {

    int n;
    cin >> n;
    int p[n + 1];
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    vector<int> path = paidStairCases(n, p);
    reverse(path.begin(),path.end());
    for (auto v = path.begin(); v < path.end(); v++) {
        cout << *v << " ";
    }

    return 0;
}