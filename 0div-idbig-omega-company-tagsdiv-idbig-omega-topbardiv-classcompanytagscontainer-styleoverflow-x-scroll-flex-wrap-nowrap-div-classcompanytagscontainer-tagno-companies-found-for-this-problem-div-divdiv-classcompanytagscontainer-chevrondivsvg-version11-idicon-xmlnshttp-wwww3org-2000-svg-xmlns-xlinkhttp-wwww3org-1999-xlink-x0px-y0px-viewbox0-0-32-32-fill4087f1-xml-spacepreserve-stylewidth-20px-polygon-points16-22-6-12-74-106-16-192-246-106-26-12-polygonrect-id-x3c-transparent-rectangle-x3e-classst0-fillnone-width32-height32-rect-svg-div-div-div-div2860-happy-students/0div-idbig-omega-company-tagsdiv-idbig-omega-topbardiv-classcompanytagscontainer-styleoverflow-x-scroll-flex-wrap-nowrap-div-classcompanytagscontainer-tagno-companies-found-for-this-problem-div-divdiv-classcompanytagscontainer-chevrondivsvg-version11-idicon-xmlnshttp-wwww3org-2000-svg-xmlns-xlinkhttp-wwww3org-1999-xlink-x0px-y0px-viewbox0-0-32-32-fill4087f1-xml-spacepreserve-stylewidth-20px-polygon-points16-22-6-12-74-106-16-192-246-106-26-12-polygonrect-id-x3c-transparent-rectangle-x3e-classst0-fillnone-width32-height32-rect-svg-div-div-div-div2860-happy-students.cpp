class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        if(nums[0]>0)ans++;//selected=0
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1&&nums[i]<i+1)ans++;
            else if(nums[i]<i+1&&(i+1<nums[i+1]))ans++;
        }
        return ans;
    }
};