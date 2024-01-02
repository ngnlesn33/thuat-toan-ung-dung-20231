#include <bits/stdc++.h>
// Problem: Given an array of integers a[1]...a[n], find number of a pair of integers whose absolute difference is  1 and a[i] < a[j].
// Input: 6
// 1 2 2 3 4 5
// Output: 5
// Explanation: There are 5 pairs of integers in the set with an absolute difference of 1.
// They are (1, 2), (2, 3), (2, 3), (3, 4), (4, 5).
using namespace std;



// Can you solve this problem using two pointers?
//int solve(int n, vector<int> &a){
//    sort(a.begin(), a.end());
//    int count = 0;
//    for(int i = 0; i < n; ++i){
//        int j = i + 1;
//        while(j < n && a[j] - a[i] <= 1){
//            j++;
//        }
//        count = max(count, j - i);
//    }
//    return count;
//}

//int solve(int n, const vector<int> &a) {
//    int count = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            if (a[j] - a[i] == 1 || a[i] - a[j] == 1) {
//                count++;
//            }
//        }
//    }
//    return count;
//}
// Can you solve this problem ?
//int solve(int n, const vector<int> &a) {
//    int count = 0;
//    for (int i = 0; i < n; ++i) {
//        int j = i + 1;
//        while (j < n && a[j] - a[i] <= 1) {
//            j++;
//        }
//        count = max(count, j - i);
//    }
//    return count;
//}

int solve(int n, const vector<int> &a) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        while (j < n && (a[j] - a[i] == 1 || a[i] - a[j] == 1)) {
            j++;
        }
        count = max(count, j - i);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) {
        cin >> i;
    }
    cout << solve(n, a) << endl;
    return 0;
}