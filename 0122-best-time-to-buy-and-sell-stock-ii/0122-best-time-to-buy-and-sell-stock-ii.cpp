class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN; // Initialize to a very small value for the first day
        for (int i = 1; i <= prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
        }
        return dp[prices.size()][0];
    }
};
