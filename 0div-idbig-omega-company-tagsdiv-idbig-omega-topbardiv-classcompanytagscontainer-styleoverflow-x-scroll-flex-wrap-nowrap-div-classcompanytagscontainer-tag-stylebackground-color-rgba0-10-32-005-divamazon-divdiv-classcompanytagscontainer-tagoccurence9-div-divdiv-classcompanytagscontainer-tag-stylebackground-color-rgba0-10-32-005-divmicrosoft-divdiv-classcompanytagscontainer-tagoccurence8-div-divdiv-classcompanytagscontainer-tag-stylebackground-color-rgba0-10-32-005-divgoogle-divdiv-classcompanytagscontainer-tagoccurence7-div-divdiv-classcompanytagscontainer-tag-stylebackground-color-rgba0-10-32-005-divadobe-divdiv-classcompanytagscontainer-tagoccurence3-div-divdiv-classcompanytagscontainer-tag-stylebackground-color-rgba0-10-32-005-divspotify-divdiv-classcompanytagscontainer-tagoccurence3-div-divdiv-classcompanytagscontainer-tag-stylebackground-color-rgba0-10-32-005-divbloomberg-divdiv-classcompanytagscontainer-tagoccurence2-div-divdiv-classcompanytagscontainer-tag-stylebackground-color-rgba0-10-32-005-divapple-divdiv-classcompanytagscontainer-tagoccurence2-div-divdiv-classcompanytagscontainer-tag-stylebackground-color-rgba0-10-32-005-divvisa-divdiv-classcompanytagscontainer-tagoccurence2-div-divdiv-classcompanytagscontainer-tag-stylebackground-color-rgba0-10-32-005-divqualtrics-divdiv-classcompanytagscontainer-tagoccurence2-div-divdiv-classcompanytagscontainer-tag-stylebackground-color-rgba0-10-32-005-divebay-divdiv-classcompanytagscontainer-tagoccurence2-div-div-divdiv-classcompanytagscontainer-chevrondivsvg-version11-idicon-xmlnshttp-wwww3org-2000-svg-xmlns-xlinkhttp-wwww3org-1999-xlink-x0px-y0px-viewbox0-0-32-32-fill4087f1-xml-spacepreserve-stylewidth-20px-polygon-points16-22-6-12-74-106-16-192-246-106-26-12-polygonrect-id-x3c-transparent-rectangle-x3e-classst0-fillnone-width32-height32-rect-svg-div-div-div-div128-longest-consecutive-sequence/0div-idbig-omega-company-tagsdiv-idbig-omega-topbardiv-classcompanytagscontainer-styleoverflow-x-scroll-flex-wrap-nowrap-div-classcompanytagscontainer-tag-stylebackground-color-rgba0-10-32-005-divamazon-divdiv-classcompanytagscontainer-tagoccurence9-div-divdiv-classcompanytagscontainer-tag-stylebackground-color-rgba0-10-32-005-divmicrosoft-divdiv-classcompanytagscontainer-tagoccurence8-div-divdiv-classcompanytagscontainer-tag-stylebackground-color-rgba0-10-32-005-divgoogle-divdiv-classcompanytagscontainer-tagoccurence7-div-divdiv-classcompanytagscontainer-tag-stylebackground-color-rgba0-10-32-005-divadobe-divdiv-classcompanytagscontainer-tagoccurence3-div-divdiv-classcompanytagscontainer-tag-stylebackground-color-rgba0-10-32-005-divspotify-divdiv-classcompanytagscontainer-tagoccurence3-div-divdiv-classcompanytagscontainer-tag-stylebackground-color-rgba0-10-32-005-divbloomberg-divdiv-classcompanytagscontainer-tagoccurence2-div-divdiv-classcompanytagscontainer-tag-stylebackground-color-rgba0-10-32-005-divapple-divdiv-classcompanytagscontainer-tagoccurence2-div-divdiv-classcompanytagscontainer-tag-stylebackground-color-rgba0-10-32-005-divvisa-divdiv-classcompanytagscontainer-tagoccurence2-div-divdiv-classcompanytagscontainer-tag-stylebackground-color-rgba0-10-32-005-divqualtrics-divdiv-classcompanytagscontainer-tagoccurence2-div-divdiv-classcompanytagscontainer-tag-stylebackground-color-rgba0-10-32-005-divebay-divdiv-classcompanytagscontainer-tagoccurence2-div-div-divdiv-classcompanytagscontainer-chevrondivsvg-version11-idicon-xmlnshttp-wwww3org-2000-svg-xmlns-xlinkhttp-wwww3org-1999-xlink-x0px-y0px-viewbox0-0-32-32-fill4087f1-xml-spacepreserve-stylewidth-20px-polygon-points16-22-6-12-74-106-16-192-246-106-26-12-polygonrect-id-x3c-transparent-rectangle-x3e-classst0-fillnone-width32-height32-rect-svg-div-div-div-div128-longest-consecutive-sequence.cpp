class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        int ans=1,cnt=0,smallest=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1==smallest){
                cnt++;smallest=nums[i];
            }
            else if(nums[i]>smallest){
                cnt=1;smallest=nums[i];
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};