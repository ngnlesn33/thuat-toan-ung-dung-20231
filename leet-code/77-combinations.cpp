#include <bits/stdc++.h>
/* Link: https://leetcode.com/problems/combinations/
 * Problem: Given two integers n and k, return all possible combinations of k numbers out of [1 ... n].
 * You may return the answer in any order.
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 */
using namespace std;

void backtrack(int n, int k, vector<vector<int>> &res, vector<int> &currentCollection, vector<bool> &visited, int index) {
    if (currentCollection.size() == k) {
        res.push_back(currentCollection);
        return;
    }
    for (int i = index; i <= n; ++i) {
//        if (visited[i]) continue;
//        visited[i] = true;
        currentCollection.push_back(i);
        backtrack(n, k, res, currentCollection, visited,i+1);
//        visited[i] = false;
        currentCollection.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> currentCollection;
    vector<bool> visited(n + 1, false);
    vector<int> nums(n + 1);
    backtrack(n, k, res, currentCollection, visited,1);
//    for (auto &i: res) {
//        sort(i.begin(), i.end());
//    }
//    // Remove duplicates
//    sort(res.begin(), res.end());
//    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> res = combine(n, k);

    for (auto &i: res) {
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
