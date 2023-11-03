class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //to take the zeros into account we use prefix sum
        unordered_map<int,int>mp;int count=0,psum=0;
        //prefix sum
       for(int i=0;i<nums.size();i++){
           psum+=nums[i];
           if(psum==goal)count++;
           if(mp.find(psum-goal)!=mp.end())
           count+=mp[psum-goal];
           mp[psum]++;
       }
       return count;
    }
};