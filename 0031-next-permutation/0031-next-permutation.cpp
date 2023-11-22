class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dip=-1,n=nums.size();
        //step1:find the dip
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                dip=i;break;
            }
        }
        if(dip==-1){//no dip
            reverse(nums.begin(),nums.end());return;
        }
        //step2:find the just greater element in the dip part
        for(int i=n-1;i>dip;i--){
            if(nums[i]>nums[dip]){
                swap(nums[i],nums[dip]);break;
            }
        }
        //reverse the already sorted dip part
        reverse(nums.begin()+dip+1,nums.end());
    }
};