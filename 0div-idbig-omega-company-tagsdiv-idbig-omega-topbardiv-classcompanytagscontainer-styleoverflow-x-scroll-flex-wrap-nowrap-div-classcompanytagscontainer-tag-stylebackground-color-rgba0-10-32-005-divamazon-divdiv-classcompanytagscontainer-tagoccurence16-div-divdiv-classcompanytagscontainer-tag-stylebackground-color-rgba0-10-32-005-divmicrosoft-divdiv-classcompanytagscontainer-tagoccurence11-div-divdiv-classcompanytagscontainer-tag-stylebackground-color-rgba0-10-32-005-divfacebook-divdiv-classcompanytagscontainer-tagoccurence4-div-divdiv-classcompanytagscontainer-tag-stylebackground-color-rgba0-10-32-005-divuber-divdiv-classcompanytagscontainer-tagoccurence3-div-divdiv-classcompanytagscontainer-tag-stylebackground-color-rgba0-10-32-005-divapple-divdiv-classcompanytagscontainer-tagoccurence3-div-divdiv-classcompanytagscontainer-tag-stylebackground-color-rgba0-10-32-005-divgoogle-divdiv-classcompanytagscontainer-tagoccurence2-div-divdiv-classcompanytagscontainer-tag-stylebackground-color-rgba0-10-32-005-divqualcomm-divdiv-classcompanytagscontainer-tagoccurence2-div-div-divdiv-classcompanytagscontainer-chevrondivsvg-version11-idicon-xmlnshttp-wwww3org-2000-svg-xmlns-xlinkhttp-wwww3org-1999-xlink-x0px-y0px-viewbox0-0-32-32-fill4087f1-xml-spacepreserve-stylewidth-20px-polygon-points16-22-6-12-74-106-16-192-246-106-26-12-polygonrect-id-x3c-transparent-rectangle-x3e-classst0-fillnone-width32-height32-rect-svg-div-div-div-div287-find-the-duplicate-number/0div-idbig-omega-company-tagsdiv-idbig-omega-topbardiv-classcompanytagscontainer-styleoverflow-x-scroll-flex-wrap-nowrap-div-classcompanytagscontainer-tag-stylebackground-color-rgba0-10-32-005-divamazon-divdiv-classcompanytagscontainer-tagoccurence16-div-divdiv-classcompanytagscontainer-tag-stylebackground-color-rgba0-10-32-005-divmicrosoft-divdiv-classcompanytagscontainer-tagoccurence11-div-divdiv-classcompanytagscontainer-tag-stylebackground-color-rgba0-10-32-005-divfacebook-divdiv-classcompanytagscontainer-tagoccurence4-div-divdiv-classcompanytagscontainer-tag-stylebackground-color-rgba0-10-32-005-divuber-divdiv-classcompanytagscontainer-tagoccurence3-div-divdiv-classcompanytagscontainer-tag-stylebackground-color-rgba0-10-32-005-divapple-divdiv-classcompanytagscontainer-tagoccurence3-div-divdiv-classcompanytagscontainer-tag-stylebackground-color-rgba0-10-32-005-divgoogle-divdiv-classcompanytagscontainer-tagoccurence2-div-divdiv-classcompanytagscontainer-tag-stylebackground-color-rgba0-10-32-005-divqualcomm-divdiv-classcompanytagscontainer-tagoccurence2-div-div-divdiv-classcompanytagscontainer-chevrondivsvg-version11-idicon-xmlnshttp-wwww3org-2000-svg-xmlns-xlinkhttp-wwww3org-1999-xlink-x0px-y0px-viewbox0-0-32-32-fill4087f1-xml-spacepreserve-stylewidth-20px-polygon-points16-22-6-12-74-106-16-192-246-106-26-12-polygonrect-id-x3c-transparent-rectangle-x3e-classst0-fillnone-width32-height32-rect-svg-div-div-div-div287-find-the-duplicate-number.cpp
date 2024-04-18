class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0,n=nums.size();
         while(i<n){
            int correct=nums[i]-1;
            if(nums[i]!=nums[correct])
            swap(nums[i],nums[correct]);
            else{
                i++;
            }
         }
         for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return nums[i];
         }
         return -1;
    }
};