class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> v;

        for (int num : arr) {
            v.push_back({abs(num - x), num});
        }
        sort(v.begin(), v.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};