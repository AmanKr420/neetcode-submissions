class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &p : freq) {
            int num = p.first;
            int frequency = p.second;

            bucket[frequency].push_back(num);
        }

        vector<int> ans;
        for (int f = nums.size(); f >= 1; f--) {

            for (int num : bucket[f]) {

                ans.push_back(num);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};