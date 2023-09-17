class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),r=n-1,l=n/2-1,count=0;
        while(l>=0){
            if(nums[l]*2<=nums[r]){
                count+=2;l--;r--;
            }
            else
            l--;
        }
        return count;
    }
};