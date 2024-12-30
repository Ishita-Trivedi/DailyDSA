class Solution {
public:
    int mod=1e9+7;
    vector<int>dp;
    int helper(int len,int low,int high,int zero,int one){
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];
        int sum=0;
        if(len>=low&&len<=high)
        sum++;
        sum %=mod;
        sum=(sum+(helper(len+zero,low,high,zero,one)%mod))%mod;
        sum=(sum+(helper(len+one,low,high,zero,one)%mod))%mod;
        return dp[len]=sum%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp=vector<int>(high+1,-1);
        return helper(0,low,high,zero,one);
    }
};