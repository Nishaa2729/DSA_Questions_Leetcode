class Solution {
public:
    int longestKSubstr(string& s, int k) {
        int n = s.size();

        int left = 0;
        int ans = -1;

        unordered_map<char, int> freq;

        for (int right = 0; right < n; right++) {
            // Add current character
            freq[s[right]]++;

            // If distinct characters become more than k,
            // shrink the window
            while (freq.size() > k) {
                freq[s[left]]--;

                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            // If exactly k distinct characters
            if (freq.size() == k) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};