#include <bits/stdc++.h>

using namespace std;

int maxContiguousSubarraySum(vector<int> &nums) {
    auto lengthOfNums = nums.size();
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];

    // We start at index 1
    for (int i = 1; i < lengthOfNums; ++i) {
        maxEndingHere = max(nums[i], nums[i] + maxEndingHere);

        // Did we beat the maxSoFar with maxEndingHere ??
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main() {
    int lengthOfNums;
    cin >> lengthOfNums;
    vector<int> nums(lengthOfNums);
    for (int i = 0; i < lengthOfNums; ++i) {
        cin >> nums[i];
    }
    cout << maxContiguousSubarraySum(nums);
    return 0;
}