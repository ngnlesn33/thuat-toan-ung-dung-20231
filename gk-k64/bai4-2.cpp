#include <iostream>
#include <vector>

int solve(std::vector<int> &nums, int target, int i, int curr_sum) {
    if (i == nums.size()) {
        if (curr_sum == target) {
            return 1;
        }
        return 0;
    }
    return solve(nums, target, i + 1, curr_sum + nums[i]) + solve(nums, target, i + 1, curr_sum - nums[i]);
}

int main() {
    std::vector<int> nums = {3, 2, 7, 5, 2, 3};
    int target = 12;
    int num_solutions = solve(nums, target, 1, nums[0]);
    std::cout << num_solutions << std::endl;
    return 0;
}
