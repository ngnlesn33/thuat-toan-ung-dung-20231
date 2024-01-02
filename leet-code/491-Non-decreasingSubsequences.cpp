#include "bits/stdc++.h"

using namespace std;

// ? Where is the duplicate come from? (Hint: nums[i] == nums[i - 1])
// ? How to avoid the duplicate?  (Hint: use set)
void backtrack(const vector<int> &nums, vector<vector<int>> &result, vector<int> temp, int index) {
    if (temp.size() >= 2) {
        result.push_back(temp);
    }
    set<int> s;
    for (int i = index; i < nums.size(); ++i) {
        if (i > index && nums[i] == nums[i - 1]) {
            continue;
        }
        // Trick: temp.back() > nums[i] is not enough, because we need to check if nums[i] is already in the set or not.
        // If it is already in the set, then we don't need to add it to the temp vector.
        if (!temp.empty() && nums[i] < temp.back() || s.find(nums[i]) != s.end()) {
            continue;
        }
        s.insert(nums[i]);
        temp.push_back(nums[i]);
        backtrack(nums, result, temp, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> findSubsequences(const vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> temp;
    backtrack(nums, result, temp, 0);
    return result;
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 1, 1, 1};
    vector<vector<int>> result = findSubsequences(nums);
    for (auto &i: result) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
