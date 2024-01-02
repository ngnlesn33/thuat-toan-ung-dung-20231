#include <bits/stdc++.h>

/*
 * Link: https://leetcode.com/problems/target-sum/
 * Problem: You are given an integer array nums and an integer target. You want to build an expression out of nums by
 * adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers. For example,
 * if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
 * Return the number of different expressions that you can build, which evaluates to target.
 * Input: nums = [1,1,1,1,1], target = 3
 * Output: 5
 * Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
 * Input: nums = [1], target = 1
 * Output: 1
 */

using namespace std;


void backtrack(const vector<int> &nums, int target, int currentSum, int index, int &count) {
    int n = nums.size();
    if (index == n) {
        if (currentSum == target)
            count++;
        return;
    }

    currentSum += nums[index];
    backtrack(nums, target, currentSum, index + 1, count);
    currentSum -= nums[index];

    currentSum -= nums[index];
    backtrack(nums, target, currentSum, index + 1, count);
    currentSum += nums[index];
}
//    if (index == nums.size()) {
//        if (currentSum == target) count++;
//        return;
//    }
//    backtrack(nums, target, currentSum + nums[index], index + 1, count);
//    backtrack(nums, target, currentSum - nums[index], index + 1, count);
//}

int findTargetSumWays(const vector<int> &nums, int target) {
    int count = 0;
    backtrack(nums, target, 0, 0, count);
    return count;
}

int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    int target = 3;
    cout << findTargetSumWays(nums, target);
    return 0;
}