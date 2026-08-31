class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Put nums[i] in its correct position.
            while (nums[i] >= 1 &&
                   nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {

                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first number that is not in its correct position.
        for (int i = 0; i < n; i++) {

            if (nums[i] != i + 1)
                return i + 1;
        }

        // If 1..n are all present,
        // the answer is n+1.
        return n + 1;
    }
};