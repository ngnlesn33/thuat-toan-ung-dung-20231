#include<bits/stdc++.h>

using namespace std;

int main() {
    int numOfElements, A, B;
    cin >> numOfElements >> A >> B;
    vector<int> nums(numOfElements);
    for (int i = 0; i < numOfElements; ++i) {
        cin >> nums[i];
    }
    // Use a set to store the unique collections
    set<vector<int>> res;
    // Use a bit mask to generate all possible subsets
    for (int mask = 0; mask < (1 << numOfElements); ++mask) {
        vector<int> currentCollection;
        int currentSum = 0;
        for (int i = 0; i < numOfElements; ++i) {
            if (mask & (1 << i)) {
                currentCollection.push_back(nums[i]);
                currentSum += nums[i];
            }
        }
        // Check if the sum is within the range
        if (currentSum >= A && currentSum <= B) {
            res.insert(currentCollection);
        }
    }
    // Print the size and the elements of the set
    cout << res.size() << endl;
    for (auto& collection : res) {
        for (int num : collection) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
