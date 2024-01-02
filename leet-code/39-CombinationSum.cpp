#include <bits/stdc++.h>

/*
 * Problem: Given an array of distinct integers candidates and a target integer target, return a list of all unique
 * combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
 * The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
 * frequency of at least one of the chosen numbers is different.
 * Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
 */

using namespace std;


void backtrack(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> currentCollection,
               int currentSum, int index) {
    if (currentSum == target) {
        res.push_back(currentCollection);
        return;
    }
    if (currentSum > target) {
        return;
    }
    for (int i = index; i < candidates.size(); ++i) {
        currentCollection.push_back(candidates[i]);
        currentSum += candidates[i];
        backtrack(candidates, target, res, currentCollection, currentSum, i);
        currentSum -= candidates[i];
        currentCollection.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> currentCollection;
    backtrack(candidates, target, res, currentCollection, 0, 0);
    return res;
}

int main() {
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = combinationSum(candidates, target);
    for (auto &i: res) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
