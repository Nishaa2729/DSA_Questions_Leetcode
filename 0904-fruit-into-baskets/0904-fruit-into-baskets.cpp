class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int low = 0;
        int n = fruits.size();
        int result = 0;

        unordered_map<int, int> freq;

        for (int high = 0; high < n; high++) {

            freq[fruits[high]]++;

            while (freq.size() > 2) {

                freq[fruits[low]]--;

                if (freq[fruits[low]] == 0) {
                    freq.erase(fruits[low]);
                }

                low++;
            }

            int length = high - low + 1;

            result = max(result, length);
        }

        return result;
    }
};