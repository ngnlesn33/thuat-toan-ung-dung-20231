#include <bits/stdc++.h>

using namespace std;

int longestCommonSubSq(string str1, string str2) {
    auto rows = str1.length() + 1;
    auto cols = str2.length() + 1;
    int LCS_table[rows][cols];
    // Filling 0's in the matrix
    for (int i = 0; i < rows; i++)
        LCS_table[i][0] = 0;
    for (int i = 0; i < cols; i++)
        LCS_table[0][i] = 0;
    int maxLen = 0;
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
                if (LCS_table[i][j] > maxLen) {
                    maxLen = LCS_table[i][j];
                }
            } else {
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
            }
        }
    }
    return maxLen;
}

int longestCommonSubSq(const vector<int> &arr1, const vector<int> &arr2) {

    int len1 = arr1.size();
    int len2 = arr2.size();

    auto rows = len1 + 1;
    auto cols = len2 + 1;
    vector<vector<int>> LCS_table(len1 + 1, vector<int>(len2 + 1, 0));

    // Filling 0's in the matrix
    for (int i = 0; i < rows; i++)
        LCS_table[i][0] = 0;
    for (int i = 0; i < cols; i++)
        LCS_table[0][i] = 0;
    int maxLen = 0;
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (arr1[i - 1] == arr2[j - 1]) {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
                if (LCS_table[i][j] > maxLen) {
                    maxLen = LCS_table[i][j];
                }
            } else {
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
            }
        }
    }
    return maxLen;
}

int main() {
//    string str1, str2;
//    cin >> str1 >> str2;
    int len1 = 0, len2 = 0;

    cin >> len1 >> len2;

    vector<int> arr1(len1), arr2(len2);

    for (int i = 0; i < len1; ++i) {
        cin >> arr1[i];
    }
    for (int i = 0; i < len2; ++i) {
        cin >> arr2[i];
    }
    cout << longestCommonSubSq(arr1, arr2);
    return 0;
}