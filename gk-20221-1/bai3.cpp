#include <bits/stdc++.h>

using namespace std;

void backtracking(int numOfElements, int A, int B, vector<int> &nums, vector<int> &currentCollection,
                  vector<vector<int>> &res, int start);


int main() {
    int numOfElements, A, B;
    cin >> numOfElements >> A >> B;
    vector<int> nums(numOfElements);
    for (int i = 0; i < numOfElements; ++i) {
        cin >> nums[i];
    }
    vector<int> currentCollection;
    vector<vector<int>> res;
    backtracking(numOfElements, A, B, nums, currentCollection, res, 0);
    cout << res.size() << endl;
}

void backtracking(int numOfElements, int A, int B, vector<int> &nums, vector<int> &currentCollection,
                  vector<vector<int>> &res, int start) {
    // The base cases(The goal of the problem)
    int currentSum = accumulate(currentCollection.begin(), currentCollection.end(), 0);
    // If goal is found
    if (currentSum >= A && currentSum <= B) {
        res.push_back(currentCollection);
    }
    // Space of making choice
    for (int i = start; i < numOfElements; ++i) {
        // Making choice
        currentCollection.push_back(nums[i]);
        // Constraints of the problem, if the constraints not satisfied, we will not make choice. But this problem does have any constraints
        // Continue to make choice
        backtracking(numOfElements, A, B, nums, currentCollection, res, i + 1);
        // If the decision not workout Undo the choice
        currentCollection.pop_back();

    }
}
