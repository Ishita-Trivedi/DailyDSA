class Solution {
public:
    int sum=0;
    void helper(int i,int x,vector<int>&nums){
        if(i>=nums.size()){
            sum+=x;
            return;
        }
        //take
        helper(i+1,x^nums[i],nums);
        helper(i+1,x,nums);
    }
    int subsetXORSum(vector<int>& nums) {
        helper(0,0,nums);
        return sum;
    }
};