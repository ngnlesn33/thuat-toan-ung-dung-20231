#include<bits/stdc++.h>

/*
 * Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Problem: Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the
 * number could represent. Return the answer in any order. A mapping of digit to letters (just like on the telephone
 * buttons) is given below. Note that 1 does not map to any letters.
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * Input: digits = ""
 * Output: []
 * Input: digits = "2"
 * Output: ["a","b","c"]
 */

using namespace std;

//vector<string> letterCombinations(const string &digits) {
//    vector<string> phone{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, res;
//    if (digits.empty()) return res;
//    res.emplace_back("");
//    for (char digit: digits) {
//        vector<string> temp;
//        for (char letter: phone[digit - '0']) {
//            for (const string &combination: res) {
//                temp.push_back(combination + letter);
//            }
//        }
//        res = temp;
//    }
//    return res;
//}

void backtrack(const string &digits, int idx, const vector<string> &phone, vector<string> &res, string ans) {
    if (digits.empty()) return;
    if (idx == digits.length()) {
        res.push_back(ans);
        return;
    }
    int digIndex = digits[idx] - '0';
    if (digIndex < 0 || digIndex > 9) return;
    string digit = phone[digits[idx] - '0'];
    for (const char &i: digit) {
        ans.push_back(i);
        backtrack(digits, idx + 1, phone, res, ans);
        ans.pop_back();
    }
}

vector<string> letterCombinations(const string &digits) {
    vector<string> phone{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, res;
    string ans;
    backtrack(digits, 0, phone, res, ans);
    return res;
}


//vector<string> letterCombinations(const string &digits) {
//    vector<string> phone{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, res;
//    if (digits.empty()) return res;
//    res.emplace_back("");
//    for (char digit: digits) {
//        vector<string> temp;
//        for (char letter: phone[digit - '0']) {
//            for (const string &combination: res) {
//                temp.push_back(combination + letter);
//            }
//        }
//        res = temp;
//    }
//    return res;
//}

int main() {
    string digits = "";
    vector<string> res = letterCombinations(digits);
    for (auto &i: res) {
        cout << i << " ";
    }
    return 0;
}


