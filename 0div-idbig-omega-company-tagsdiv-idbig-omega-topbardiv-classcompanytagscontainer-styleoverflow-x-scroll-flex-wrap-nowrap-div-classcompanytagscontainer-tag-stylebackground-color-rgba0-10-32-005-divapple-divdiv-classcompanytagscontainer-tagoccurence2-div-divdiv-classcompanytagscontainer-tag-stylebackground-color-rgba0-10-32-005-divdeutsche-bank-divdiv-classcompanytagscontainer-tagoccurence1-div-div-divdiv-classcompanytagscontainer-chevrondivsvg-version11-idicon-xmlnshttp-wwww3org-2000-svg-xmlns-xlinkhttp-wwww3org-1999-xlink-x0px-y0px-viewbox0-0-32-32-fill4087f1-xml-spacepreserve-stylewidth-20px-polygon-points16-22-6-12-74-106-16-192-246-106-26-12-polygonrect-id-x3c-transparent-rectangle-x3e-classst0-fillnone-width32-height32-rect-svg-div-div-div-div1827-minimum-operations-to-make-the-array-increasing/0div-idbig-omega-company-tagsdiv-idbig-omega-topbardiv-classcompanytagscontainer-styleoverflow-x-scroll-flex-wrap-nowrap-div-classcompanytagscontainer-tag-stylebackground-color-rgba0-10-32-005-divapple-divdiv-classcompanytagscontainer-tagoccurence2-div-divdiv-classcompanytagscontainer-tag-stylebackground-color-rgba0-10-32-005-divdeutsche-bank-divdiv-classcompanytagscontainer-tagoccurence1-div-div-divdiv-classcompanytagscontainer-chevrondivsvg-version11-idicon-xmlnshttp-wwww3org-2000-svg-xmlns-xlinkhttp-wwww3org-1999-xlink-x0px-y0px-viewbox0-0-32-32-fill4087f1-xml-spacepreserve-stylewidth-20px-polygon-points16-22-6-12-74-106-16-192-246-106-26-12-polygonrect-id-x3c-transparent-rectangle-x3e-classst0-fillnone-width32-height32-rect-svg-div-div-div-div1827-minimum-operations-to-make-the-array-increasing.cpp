class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int diff=abs(nums[i]-nums[i-1])+1;
                count+=diff;
                nums[i]+=diff;
            }
        }
        return count;
    }
};