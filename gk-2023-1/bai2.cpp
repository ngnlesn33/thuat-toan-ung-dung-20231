#include <bits/stdc++.h>
// Problem: Given an array of integers, a number k. Find number of subset in the array whose sum is bigger or equal than k
// and % 5 == 0
// Input: 4
// 1000 1600 101 200
// 1901
// Output: 2
// Explanation: There are 2 subsets in the set with sum >= 1901 and % 5 == 0. They are (1000, 101, 200) and (1600, 101).


using namespace std;

void backtrack(vector<int> &a, int k, int currentSum, int index, int &count) {
    int n = a.size();
    if (index == n) {
        if (currentSum >= k && currentSum % 5 == 0)
            count++;
        return;
    }
    backtrack(a, k, currentSum + a[index], index + 1, count);
    backtrack(a, k, currentSum, index + 1, count);
}

int solve(int n, vector<int> &a, int k) {
    int count = 0;
    backtrack(a, k, 0, 0, count);
    return count;
}

int main(){
    int n, k;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cin >> k;
    cout << solve(n, a, k);
    return 0;
}


