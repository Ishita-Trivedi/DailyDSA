class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        mp[0]=0;
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<n;i++){
            nums[i]%=k;
        }
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                int idx=mp[nums[i]];
                if((i-idx+1)>=2)return true;
            }
            else
            mp[nums[i]]=i+1;
        }
        return false;
    }
};