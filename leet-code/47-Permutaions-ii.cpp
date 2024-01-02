#include <bits/stdc++.h>
/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 * Problem: Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
 * Input: nums = [1,1,2]
 * Output: [[1,1,2],[1,2,1],[2,1,1]]
 *
 */
using namespace std;

void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &currentCollection, vector<bool> &visited) {
    int n = nums.size();
    if (currentCollection.size() == n) {
        res.push_back(currentCollection);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }
        // Trick: If the current element is equal to the previous element and the previous element is not visited, then
        // skip the current element.
        if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
            continue;
        }
        visited[i] = true;
        currentCollection.push_back(nums[i]);
        backtrack(nums, res, currentCollection, visited);
        visited[i] = false;
        currentCollection.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
//    set<vector<int>> temp;
    vector<int> currentCollection;
    vector<bool> visited(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtrack(nums, res, currentCollection, visited);
//    for (auto const &i: res) {
//        temp.insert(i);
//    }
//    vector<vector<int>> finalAnswer;
//    for (const auto &it: temp) {
//        finalAnswer.push_back(it);
//    }
    return res;
}

int main() {
    vector<int> nums{-1, 2, -1, 2, 1, -1, 2, 1};
    vector<vector<int>> finalAnswer = permuteUnique(nums);
    for (auto &i: finalAnswer) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
