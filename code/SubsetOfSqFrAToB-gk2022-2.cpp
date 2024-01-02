#include<bits/stdc++.h>

using namespace std;

void generate_collection(int numOfElements, vector<int> &currentCollection,
                         vector<vector<int>> &res, int currentSum, int A, int B, vector<int> nums, int index) {
    // Base case
    if(index == numOfElements) {
        return;
    }
    if (currentSum >= A && currentSum <= B) {
        res.push_back(currentCollection);
    }

    // Constraints
    for (int i = index; i < numOfElements; ++i) {
        currentSum += nums[i];
        currentCollection.push_back(nums[i]);
        generate_collection(numOfElements, currentCollection, res, currentSum, A, B, nums, i+1);
        currentSum -= nums[i];
        currentCollection.pop_back();
    }

}

int main() {
    int numOfElements, A, B;
    vector<int> currentCollection;
    vector<vector<int>> res;
    cin >> numOfElements >> A >> B;
    vector<int> nums(numOfElements);
    for (int i = 0; i < numOfElements; ++i) {
        cin >> nums[i];
    }
    generate_collection(numOfElements, currentCollection,
                        res, 0, A, B, nums, 0);
    cout << res.size();
    return 0;
}