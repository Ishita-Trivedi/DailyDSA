class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1,maxCount=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])count++;
            else
            count=1;
            maxCount=max(maxCount,count);
        }
        vector<vector<int>>ans(maxCount);
        int r=0;
        ans[0].push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                r++;
            }
            else
            r=0;
            ans[r].push_back(nums[i]);
        }
       return ans;
    }
};