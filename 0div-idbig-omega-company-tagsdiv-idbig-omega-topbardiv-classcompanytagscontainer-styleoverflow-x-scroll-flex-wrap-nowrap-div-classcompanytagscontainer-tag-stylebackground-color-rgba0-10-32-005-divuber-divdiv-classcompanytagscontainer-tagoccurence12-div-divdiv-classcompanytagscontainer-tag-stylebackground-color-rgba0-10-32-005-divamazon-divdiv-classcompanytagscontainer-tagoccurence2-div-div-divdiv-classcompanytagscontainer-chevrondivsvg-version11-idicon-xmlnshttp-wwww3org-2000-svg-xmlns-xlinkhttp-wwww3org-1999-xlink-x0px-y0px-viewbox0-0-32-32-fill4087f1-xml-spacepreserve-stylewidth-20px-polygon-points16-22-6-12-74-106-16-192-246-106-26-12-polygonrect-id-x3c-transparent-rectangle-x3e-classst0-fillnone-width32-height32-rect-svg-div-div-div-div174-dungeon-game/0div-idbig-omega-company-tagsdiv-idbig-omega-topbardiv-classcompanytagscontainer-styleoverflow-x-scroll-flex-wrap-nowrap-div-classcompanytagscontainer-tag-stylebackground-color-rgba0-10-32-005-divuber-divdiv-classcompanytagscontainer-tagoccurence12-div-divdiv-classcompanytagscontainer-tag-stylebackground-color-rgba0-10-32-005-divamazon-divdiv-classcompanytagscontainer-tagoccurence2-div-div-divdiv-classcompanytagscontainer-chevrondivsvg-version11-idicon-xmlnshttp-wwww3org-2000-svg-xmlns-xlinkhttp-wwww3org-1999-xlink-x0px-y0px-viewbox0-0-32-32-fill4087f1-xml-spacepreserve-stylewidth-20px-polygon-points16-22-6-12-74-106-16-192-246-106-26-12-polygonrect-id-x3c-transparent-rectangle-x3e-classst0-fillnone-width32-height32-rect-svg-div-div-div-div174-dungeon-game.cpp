class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1)continue;
                int down=(i==m-1)?INT_MAX:dp[i+1][j]-dungeon[i][j];
                int right=(j==n-1)?INT_MAX:dp[i][j+1]-dungeon[i][j];
                int val=min(right,down);
                dp[i][j]=max(val,1);
            }
        }
        return dp[0][0];
    }
};