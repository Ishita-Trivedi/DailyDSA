class Solution {
public:
    bool helper(int sum,int i,int total,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(i==nums.size()){
        if(sum&&sum==(total-sum))return dp[i][sum]=true;
           return dp[i][sum]=false;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        return dp[i][sum]=(helper(sum+nums[i],i+1,total,nums,dp)||helper(sum,i+1,total,nums,dp));
    }
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0)return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(total+1,-1));
        return helper(0,0,total,nums,dp);
    }
};