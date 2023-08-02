class Solution {
public:
    void helper(vector<int>cp,vector<vector<int>>&ans,vector<int>& nums,unordered_map<int,int>mp)
    {
        if(cp.size()==nums.size())
        {
            ans.push_back(cp);return;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(mp.find(j)==mp.end())
            {
                mp[j]++;
                cp.push_back(nums[j]);
                helper(cp,ans,nums,mp);
                cp.pop_back();
                mp.erase(j);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>cp;
        unordered_map<int,int>mp;
        helper(cp,ans,nums,mp);
        return ans;
    }
};