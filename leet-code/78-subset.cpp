#include <bits/stdc++.h>
/*
 * Problem: Given an integer array nums of unique elements, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 */

using namespace std;

void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> &currentCollection, int index) {
    result.push_back(currentCollection);
    int n = nums.size();
    for (int i = index; i < n; ++i) {
        currentCollection.push_back(nums[i]);
        backtrack(nums, result, currentCollection, i + 1);
        currentCollection.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> currentCollection;
    backtrack(nums, result, currentCollection,0);
    return result;
}

int main() {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    for (auto &i: result) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
