class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<bool>ans;
        vector<int>sum(n,0);
        for(int i=1;i<n;i++){
            bool ck=(nums[i]&1)&&(nums[i-1]&1);
            ck=ck||((nums[i]%2==0)&&(nums[i-1]%2==0));
            if(ck)
            sum[i]=1;
        }
        for(int i=1;i<n;i++)
        sum[i]+=sum[i-1];
        for(auto & q:queries){
            int s=q[0],e=q[1];
            int val=(s==0)?sum[e]:sum[e]-sum[s];
            if(val)ans.push_back(false);
            else
            ans.push_back(true);
        }
        return ans;
    }
};