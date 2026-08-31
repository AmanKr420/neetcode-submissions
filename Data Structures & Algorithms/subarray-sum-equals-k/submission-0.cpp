class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Prefix sum 0 has occurred once.
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {

            prefixSum += num;

            // We need an earlier prefix sum of prefixSum - k.
            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            // Store frequency of this prefix sum.
            mp[prefixSum]++;
        }

        return count;
    }
};