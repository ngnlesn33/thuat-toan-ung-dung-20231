#include <bits/stdc++.h>
/*
 * Problems: Given an array of numbers, print length of the longest increasing subsequence.

 */
using namespace std;

int lengthOfLIS(vector<int> &nums) {
    int currentMax = 1;
    int maxSoFar = 1;
    auto lengthOfNums = nums.size();
    for (int i = 0; i < lengthOfNums; ++i) {
        if (nums[i + 1] > nums[i]) {
            currentMax++;
        } else {
            maxSoFar = max(maxSoFar, currentMax);
            currentMax = 0;
        }
    }
    return maxSoFar;
}

int main() {
    int numOfElements;
    cin >> numOfElements;
    vector<int> nums(numOfElements + 1, 0);
    for (int i = 0; i < numOfElements; ++i) {
        cin >> nums[i];
    }
    cout << lengthOfLIS(nums);
}