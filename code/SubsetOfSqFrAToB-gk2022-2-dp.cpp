#include<bits/stdc++.h>

using namespace std;

int countSubcollections(int numOfElements, vector<int>& nums, int A, int B) {
    int result = 0;

    vector<vector<int>> dp(numOfElements + 1, vector<int>(B + 1, 0));

    for (int i = 0; i <= numOfElements; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= numOfElements; ++i) {
        for (int j = nums[i - 1]; j <= B; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        }
    }

    for (int i = A; i <= B; ++i) {
        result += dp[numOfElements][i];
    }

    return result;
}

int main() {
    int numOfElements, A, B;
    cin >> numOfElements >> A >> B;
    vector<int> nums(numOfElements);
    for (int i = 0; i < numOfElements; ++i) {
        cin >> nums[i];
    }

    int result = countSubcollections(numOfElements, nums, A, B);
    cout << result << endl;

    return 0;
}
