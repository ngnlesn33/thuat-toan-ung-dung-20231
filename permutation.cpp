#include <bits/stdc++.h>

using namespace std;

void permutation(vector<int> &nums, int &count, vector<bool> &visited, vector<int> &currentCollection) {

    int n = nums.size();
    if (currentCollection.size() == n) {
        count++;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            currentCollection.push_back(nums[i]);
            permutation(nums, count, visited, currentCollection);
            visited[i] = false;
            currentCollection.pop_back();
        }
    }
}

int main() {
    vector<int> nums{1, 2, 3};
    int count = 0;
    int n = nums.size();
    vector<bool> visited(n, false);
    vector<int> currentCollection;
    permutation(nums, count, visited, currentCollection);
    cout << count;
}