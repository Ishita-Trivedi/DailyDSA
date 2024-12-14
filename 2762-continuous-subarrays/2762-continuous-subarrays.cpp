class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count=0;
        int n=nums.size(),l=0,r=0;
        map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.rbegin()->first-mp.begin()->first>2){
                if(--mp[nums[l]]==0)
                mp.erase(nums[l]);
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
};