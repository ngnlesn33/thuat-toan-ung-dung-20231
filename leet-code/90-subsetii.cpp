#include "bits/stdc++.h"

/*
 * Problem: Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 */

using namespace std;

void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> &currentCollection, int index) {
    result.push_back(currentCollection);
    int n = nums.size();
    for (int i = index; i < n; i++) {
        if (i != index && nums[i] == nums[i - 1])
            continue;
        currentCollection.push_back(nums[i]);
        backtrack(nums, result, currentCollection, i + 1);
        currentCollection.pop_back();
    }
}


vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> currentCollection;
    sort(nums.begin(), nums.end());
    backtrack(nums, result, currentCollection, 0);
    return result;
}

int main() {
    vector<int> nums{1, 2, 2};
    vector<vector<int>> result = subsetsWithDup(nums);
    for (auto &i: result) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
