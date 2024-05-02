class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int>mp;
        int maxi=INT_MIN;
        for(int x:nums){
            if(x<0)mp[x]++;
        }
        for(int x:nums){
            if(x>0&&mp.find(-x)!=mp.end()){
                maxi=max(maxi,x);
            }
        }
        if(maxi==INT_MIN)return -1;
        return maxi;
    }
};