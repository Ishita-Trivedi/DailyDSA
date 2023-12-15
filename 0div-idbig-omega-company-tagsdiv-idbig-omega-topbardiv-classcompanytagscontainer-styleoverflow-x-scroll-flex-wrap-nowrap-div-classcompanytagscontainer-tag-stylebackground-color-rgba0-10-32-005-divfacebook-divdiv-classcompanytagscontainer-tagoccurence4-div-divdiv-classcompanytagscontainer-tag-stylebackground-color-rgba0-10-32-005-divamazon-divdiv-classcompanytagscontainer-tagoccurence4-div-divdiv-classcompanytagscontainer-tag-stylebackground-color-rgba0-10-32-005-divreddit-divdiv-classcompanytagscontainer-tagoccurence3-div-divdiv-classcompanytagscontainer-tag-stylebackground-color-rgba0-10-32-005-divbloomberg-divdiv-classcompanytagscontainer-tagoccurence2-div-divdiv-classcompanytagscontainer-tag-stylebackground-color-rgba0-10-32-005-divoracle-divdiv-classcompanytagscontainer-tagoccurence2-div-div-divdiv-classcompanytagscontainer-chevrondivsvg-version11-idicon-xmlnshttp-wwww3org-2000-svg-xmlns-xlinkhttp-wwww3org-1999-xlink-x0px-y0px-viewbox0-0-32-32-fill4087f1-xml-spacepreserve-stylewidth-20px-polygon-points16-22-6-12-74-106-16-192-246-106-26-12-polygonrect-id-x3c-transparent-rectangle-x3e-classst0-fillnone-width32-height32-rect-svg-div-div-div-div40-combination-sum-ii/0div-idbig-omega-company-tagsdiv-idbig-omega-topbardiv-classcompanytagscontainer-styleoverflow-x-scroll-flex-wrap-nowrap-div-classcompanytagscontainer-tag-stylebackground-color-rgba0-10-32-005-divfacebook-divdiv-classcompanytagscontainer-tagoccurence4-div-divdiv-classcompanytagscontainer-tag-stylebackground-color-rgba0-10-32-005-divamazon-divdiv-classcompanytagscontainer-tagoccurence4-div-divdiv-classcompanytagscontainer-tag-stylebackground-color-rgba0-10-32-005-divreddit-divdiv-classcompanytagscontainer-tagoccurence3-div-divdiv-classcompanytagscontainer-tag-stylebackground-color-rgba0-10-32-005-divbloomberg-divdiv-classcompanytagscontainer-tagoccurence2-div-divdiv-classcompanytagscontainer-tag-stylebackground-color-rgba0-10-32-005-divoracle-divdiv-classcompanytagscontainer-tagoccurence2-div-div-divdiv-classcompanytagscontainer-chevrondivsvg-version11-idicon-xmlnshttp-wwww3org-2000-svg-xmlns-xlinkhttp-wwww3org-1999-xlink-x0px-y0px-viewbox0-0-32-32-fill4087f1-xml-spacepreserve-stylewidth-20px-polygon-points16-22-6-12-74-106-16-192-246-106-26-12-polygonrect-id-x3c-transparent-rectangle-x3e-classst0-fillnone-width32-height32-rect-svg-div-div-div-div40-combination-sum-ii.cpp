class Solution {
private:
    void helper(int ind,int target,vector<int>& candidates, vector<int>temp, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            temp.push_back(candidates[i]);
            helper(i+1,target-candidates[i],candidates,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        helper(0,target,candidates,temp,ans);
        return ans;
    }
};