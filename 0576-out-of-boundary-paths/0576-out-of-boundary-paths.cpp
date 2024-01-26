class Solution {
 int mod=1e9+7;
 int ix[4]={1,-1,0,0};
 int iy[4]={0,0,1,-1};
 private:
    int helper(int i,int j,int maxMove,int m,int n, vector<vector<vector<int>>>&dp){
         if(maxMove<0)return 0;
        if(i>=m||j>=n||i<0||j<0)return 1;
        if(dp[i][j][maxMove]!=-1)return dp[i][j][maxMove];
        int sum=0;
        for(int k=0;k<4;k++){
            int x=i+ix[k],y=j+iy[k];
            sum+=helper(x,y,maxMove-1,m,n,dp);
            sum%=mod;
        }
        return dp[i][j][maxMove]=sum%mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
        return helper(startRow,startColumn,maxMove,m,n,dp);
    }
};