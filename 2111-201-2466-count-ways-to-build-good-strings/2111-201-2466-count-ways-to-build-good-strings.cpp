class Solution {
public:
    int mod=1e9+7;
    vector<int>dp;
    int helper(int len,int low,int high,int zero,int one){
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];
        int sum=0;
        if(len>=low)//as it would be definately less than <=high
        sum++;
        sum %=mod;
        sum=(sum+(helper(len+zero,low,high,zero,one)%mod))%mod;
        sum=(sum+(helper(len+one,low,high,zero,one)%mod))%mod;
        return dp[len]=sum%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,0);
        for(int len=high;len>=0;len--){
            int sum=0;
            if(len>=low)sum++;
            if((len+zero)<=high)
            sum=(sum+dp[len+zero]%mod)% mod;
             if((len+one)<=high)
            sum=(sum+dp[len+one]%mod)% mod;
            dp[len]+=sum%mod;
        }
        return dp[0];
        // return helper(0,low,high,zero,one);
    }
};