class Solution {
public:
    int helper(int j,int place,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(j>=grid[0].size())return 0;
        if(dp[j][place]!=-1)return dp[j][place];
        int minOpr=INT_MAX,cost=0;
        for(int i=0;i<grid.size();i++){
            cost+=(grid[i][j]!=place);
        }
        int minCost=INT_MAX;
        for(int val=0;val<=9;val++){
            if(val==place)continue;
        int c=cost+helper(j+1,val,grid,dp);
        minCost=min(minCost,c);
        }
        return dp[j][place]=minCost;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid[0].size(),vector<int>(10,-1));
        int mini=INT_MAX;
        for(int val=0;val<=9;val++){
        mini=min(mini,helper(0,val,grid,dp));
        }
        return mini;
    }
};