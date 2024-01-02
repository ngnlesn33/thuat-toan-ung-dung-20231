#include <bits/stdc++.h>

/*
 * Problem statement: Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */
using namespace std;


void backtrack(const vector<int> &nums, vector<int> &currentCollection, vector<vector<int>> &res) {
    if (currentCollection.size() == nums.size()) {
        res.push_back(currentCollection);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (find(currentCollection.begin(), currentCollection.end(), nums[i]) != currentCollection.end())
            continue;
        currentCollection.push_back(nums[i]);
        backtrack(nums, currentCollection, res);
        currentCollection.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> currentCollection;
    backtrack(nums, currentCollection, res);
    return res;
}

int main() {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for (auto &i: res) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
