class Solution {
public:
    static bool compare(string &a, string &b) {
        return a.size() < b.size();
    }

    bool isPredecessor(string &a, string &b) {
        if (a.size() + 1 != b.size()) {
            return false;
        }

        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);

        int n = words.size();
        vector<int> dp(n, 1);
        int maxLength = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLength = max(maxLength, dp[i]);
                }
            }
        }

        return maxLength;
    }
};
