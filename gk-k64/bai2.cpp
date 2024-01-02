#include <bits/stdc++.h>

using namespace std;

int numOfEvenSubArr(vector<int> &nums) {
    int lengthOfNums = nums.size();
    int result = 0;
    for (int i = 0; i < lengthOfNums; ++i) {
        int currentSum = 0;
        for (int j = i; j < lengthOfNums; ++j) {
            currentSum += nums[j];
            if (currentSum % 2 == 0) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    int numOfElements;
    cin >> numOfElements;
    vector<int> nums(numOfElements);
    for (int i = 0; i < numOfElements; ++i) {
        cin >> nums[i];
    }
    cout << numOfEvenSubArr(nums);
}