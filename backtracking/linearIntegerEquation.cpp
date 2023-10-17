#include<bits/stdc++.h>

using namespace std;

// Function to generate collections using backtracking
void generate_collection(int numOfElements, int targetSum, vector<int> &currentCollection,
                         vector<vector<int>> &res, int currentSum) {
    // Base case
    if (currentCollection.size() == numOfElements && currentSum == targetSum) {
        res.push_back(currentCollection);
        return;
    }

    // Constraints
    int remaining = targetSum - currentSum;
    for (int i = 1; i <= remaining; ++i) {
        currentCollection.push_back(i);
        generate_collection(numOfElements, targetSum, currentCollection, res, currentSum + i);
        currentCollection.pop_back();
    }

}

int main() {
    int numOfElements, targetSum;
    vector<int> currentCollection;
    vector<vector<int>> res;
    cin >> numOfElements >> targetSum;
    generate_collection(numOfElements, targetSum, currentCollection,
                        res, 0);
    for (const auto &collection: res) {
        for (auto element: collection) {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}

