class Solution {
typedef long long int ll;
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),count=0;
        vector<unordered_map<ll,int>>dp(n);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff=(ll)nums[i]-(ll)nums[j];
                dp[i][diff]+=dp[j][diff]+1;
                count+=dp[j][diff];//as with this i it is now >=3 len
            }
        }
        return count;
    }
};