#include <bits/stdc++.h>

/*
 * Link: https://leetcode.com/problems/combination-sum-iii/
 * Problem: Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 * Return a list of all possible valid combinations. The list must not contain the same combination twice, and the
 * combinations may be returned in any order.
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Explanation:
 * 1 + 2 + 4 = 7
 * There are no other valid combinations.
 * Input: k = 3, n = 9
 * Output: [[1,2,6],[1,3,5],[2,3,4]]
 * Explanation:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * There are no other valid combinations.
 *
 */

using namespace std;

void backtrack(vector<vector<int>> &res, vector<int> &currentCollection, int k, int n, int index) {
    if (currentCollection.size() == k && n == 0) {
        res.push_back(currentCollection);
        return;
    }
    for (int i = index; i <= 9; i++) {
        currentCollection.push_back(i);
        backtrack(res, currentCollection, k, n - i, i + 1);
        currentCollection.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> currentCollection;
    backtrack(res, currentCollection, k, n, 1);
    return res;
}


int main() {
    int k = 3, n = 9;
    vector<vector<int>> res = combinationSum3(k, n);
    for (auto &i: res) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
