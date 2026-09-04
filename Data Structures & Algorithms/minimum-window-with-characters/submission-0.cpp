class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        unordered_map<char, int> window;

        int left = 0;
        int right = 0;

        int formed = 0;
        int required = t.size();

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] <= need[c]) {
                formed++;
            }

            while (formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char remove = s[left];
                window[remove]--;

                if (need.count(remove) &&
                    window[remove] < need[remove]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};