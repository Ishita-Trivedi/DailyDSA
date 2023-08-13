class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        for(int i=0;i<coins.size()+1;i++)
        dp[i][0]=1;
        for(int i=1;i<coins.size()+1;i++){
            for(int j=1;j<=amount;j++){
                int take=0;
                if(coins[i-1]<=j)
                take=dp[i][j-coins[i-1]];
                int ntake=dp[i-1][j];
                dp[i][j]=take+ntake;
            }
        }
        return dp[coins.size()][amount];
    }
};