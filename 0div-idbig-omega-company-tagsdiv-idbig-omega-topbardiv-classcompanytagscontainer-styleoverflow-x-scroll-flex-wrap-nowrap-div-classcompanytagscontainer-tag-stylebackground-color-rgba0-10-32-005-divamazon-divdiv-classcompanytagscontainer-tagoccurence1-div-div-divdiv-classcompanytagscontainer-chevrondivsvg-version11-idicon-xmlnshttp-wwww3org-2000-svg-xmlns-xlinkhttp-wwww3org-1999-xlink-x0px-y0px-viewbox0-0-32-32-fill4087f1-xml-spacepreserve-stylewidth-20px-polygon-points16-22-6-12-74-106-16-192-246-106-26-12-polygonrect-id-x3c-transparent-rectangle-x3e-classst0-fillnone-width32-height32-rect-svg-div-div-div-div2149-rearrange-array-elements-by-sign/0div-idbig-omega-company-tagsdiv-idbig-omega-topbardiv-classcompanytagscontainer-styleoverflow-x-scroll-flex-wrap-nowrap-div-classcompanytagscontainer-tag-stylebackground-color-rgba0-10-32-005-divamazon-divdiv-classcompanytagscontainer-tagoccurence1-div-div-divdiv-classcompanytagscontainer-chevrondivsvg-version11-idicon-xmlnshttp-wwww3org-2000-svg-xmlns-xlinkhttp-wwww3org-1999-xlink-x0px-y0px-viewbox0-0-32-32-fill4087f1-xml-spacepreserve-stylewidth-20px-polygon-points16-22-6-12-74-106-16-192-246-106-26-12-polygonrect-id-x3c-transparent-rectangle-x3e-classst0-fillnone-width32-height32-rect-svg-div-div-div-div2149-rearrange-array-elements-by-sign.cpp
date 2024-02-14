class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg,ans;
        for(int x:nums){
            if(x<0)
            neg.push_back(x);
            else
            pos.push_back(x);
        }
        int p=0,n=0;
        for(int i=0;i<nums.size();i++){
            if(i&1)//odd position
            ans.push_back(neg[n++]);
            else
            ans.push_back(pos[p++]);
        }
        return ans;
    }
};