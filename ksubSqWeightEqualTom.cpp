#include <bits/stdc++.h>

using namespace std;

int kSSqWeightEqualTom(vector<int> &nums, int lengthOfNums, int numOfSubsq, int sumOfSubsq) {
    int currentSum = 0;
    int count = 0;
    for (int i = 0; i < numOfSubsq; ++i) {
        currentSum += nums[i];
    }
    for (int i = 0; i <= lengthOfNums - numOfSubsq; ++i) {
        // check if the current sum is equal to the target sum
        if (currentSum == sumOfSubsq) count++;
        // update the current sum by subtracting the first element and adding the next element of the window
        currentSum -= nums[i];
        currentSum += nums[i + numOfSubsq];
    }
    return count;
}

int main() {
    int lengthOfNums, numOfSubsq, sumOfSubsq;
    cin >> lengthOfNums >> numOfSubsq >> sumOfSubsq;
    vector<int> nums(lengthOfNums);
    for (int i = 0; i < lengthOfNums; ++i) {
        cin >> nums[i];
    }
    cout << kSSqWeightEqualTom(nums, lengthOfNums, numOfSubsq, sumOfSubsq);
    return 0;
}