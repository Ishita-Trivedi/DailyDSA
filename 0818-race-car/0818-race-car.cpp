class Solution {
public:
    int racecar(int target) {
        vector<int>dp(target+1,1e9);
        dp[0]=0;
        int r=1;
        for(int t=1;t<=target;t++){
            if(t==pow(2,r)-1){
                dp[t]=r;
                r++;
            }
            else{
                int lb=pow(2,r-1)-1,
                ub=pow(2,r)-1;
                //go to ub then reverse
                int op1=r+1+dp[ub-t];
                //go to lb then reverse go j Acc then reverse

                for(int j=0;j<r-1;j++){
                    dp[t]=min(dp[t],r+j+1+dp[t-lb+pow(2,j)-1]);
                }
                dp[t]=min(dp[t],op1);
            }
        }
        return dp[target];
    }
};