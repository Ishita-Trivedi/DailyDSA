class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
          int sum_ans=0,len=0,maxi=INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxi=max(maxi,arr[j]);
                int sum=maxi*len+dp[j+1];
                sum_ans=max(sum_ans,sum);
            }
         dp[i]=sum_ans;  
        }
        return dp[0];
    }
};