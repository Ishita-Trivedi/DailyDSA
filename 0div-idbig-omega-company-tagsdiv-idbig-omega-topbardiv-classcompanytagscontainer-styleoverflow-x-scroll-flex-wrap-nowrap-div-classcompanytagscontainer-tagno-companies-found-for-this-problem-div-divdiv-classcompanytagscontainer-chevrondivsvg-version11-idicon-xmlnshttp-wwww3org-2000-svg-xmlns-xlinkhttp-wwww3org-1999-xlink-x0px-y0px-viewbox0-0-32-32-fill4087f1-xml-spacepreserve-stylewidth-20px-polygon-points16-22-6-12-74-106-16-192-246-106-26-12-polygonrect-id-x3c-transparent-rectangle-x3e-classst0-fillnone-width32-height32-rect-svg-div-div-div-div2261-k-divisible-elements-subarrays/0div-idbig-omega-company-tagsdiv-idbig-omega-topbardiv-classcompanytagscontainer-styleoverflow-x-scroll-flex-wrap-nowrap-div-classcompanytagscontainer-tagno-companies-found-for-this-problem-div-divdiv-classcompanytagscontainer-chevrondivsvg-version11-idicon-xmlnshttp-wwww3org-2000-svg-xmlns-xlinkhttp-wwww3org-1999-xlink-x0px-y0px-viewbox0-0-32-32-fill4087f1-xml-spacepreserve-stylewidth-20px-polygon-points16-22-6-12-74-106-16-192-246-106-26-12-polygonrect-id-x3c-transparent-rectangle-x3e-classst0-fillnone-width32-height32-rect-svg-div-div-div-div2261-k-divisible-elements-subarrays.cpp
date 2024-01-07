class Solution {
private:
    void helper(int i,set<vector<int>>&st,vector<int>& nums, int k, int p){
        if(i>=nums.size())return;
        int count=0;//count of divisible till date
        vector<int>temp;//subarrays
        for(int j=i;j<nums.size();j++){
            if(nums[j]%p==0)count++;
            if(count<=k){
                temp.push_back(nums[j]);
                st.insert(temp);
            }
        }
        helper(i+1,st,nums,k,p);
    }
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>st;
        helper(0,st,nums,k,p);
        return st.size(); 
    }
};