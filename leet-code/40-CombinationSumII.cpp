#include <bits/stdc++.h>

/*
 * Problem: Given a collection of candidate numbers (candidates) and a target number (target), find all unique
 * combinations in candidates where the candidate numbers sum to target.
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/

using namespace std;

void backtrack(vector<int> &candidates, int target, vector<int> &currentCollection,
               vector<vector<int>> &res, int currentSum, int index) {
    int numOfElements = candidates.size();
    sort(candidates.begin(), candidates.end());
    if (currentSum == target ) {
        res.push_back(currentCollection);
        return;
    } else if (currentSum > target) {
        return;
    }
//    int prev = -1;

    for (int i = index; i < numOfElements; ++i) {
        //
        if (i != index && candidates[i] == candidates[i - 1])
            continue;

        currentCollection.push_back(candidates[i]);
        currentSum += candidates[i];
        backtrack(candidates, target, currentCollection, res, currentSum, i +1);
        currentSum -= candidates[i];
        currentCollection.pop_back();
//        prev = candidates[i];
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> currentCollection;
    backtrack(candidates, target, currentCollection, res, 0, 0);
    return res;
}

int main() {
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates, target);
    for (auto &i: res) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}