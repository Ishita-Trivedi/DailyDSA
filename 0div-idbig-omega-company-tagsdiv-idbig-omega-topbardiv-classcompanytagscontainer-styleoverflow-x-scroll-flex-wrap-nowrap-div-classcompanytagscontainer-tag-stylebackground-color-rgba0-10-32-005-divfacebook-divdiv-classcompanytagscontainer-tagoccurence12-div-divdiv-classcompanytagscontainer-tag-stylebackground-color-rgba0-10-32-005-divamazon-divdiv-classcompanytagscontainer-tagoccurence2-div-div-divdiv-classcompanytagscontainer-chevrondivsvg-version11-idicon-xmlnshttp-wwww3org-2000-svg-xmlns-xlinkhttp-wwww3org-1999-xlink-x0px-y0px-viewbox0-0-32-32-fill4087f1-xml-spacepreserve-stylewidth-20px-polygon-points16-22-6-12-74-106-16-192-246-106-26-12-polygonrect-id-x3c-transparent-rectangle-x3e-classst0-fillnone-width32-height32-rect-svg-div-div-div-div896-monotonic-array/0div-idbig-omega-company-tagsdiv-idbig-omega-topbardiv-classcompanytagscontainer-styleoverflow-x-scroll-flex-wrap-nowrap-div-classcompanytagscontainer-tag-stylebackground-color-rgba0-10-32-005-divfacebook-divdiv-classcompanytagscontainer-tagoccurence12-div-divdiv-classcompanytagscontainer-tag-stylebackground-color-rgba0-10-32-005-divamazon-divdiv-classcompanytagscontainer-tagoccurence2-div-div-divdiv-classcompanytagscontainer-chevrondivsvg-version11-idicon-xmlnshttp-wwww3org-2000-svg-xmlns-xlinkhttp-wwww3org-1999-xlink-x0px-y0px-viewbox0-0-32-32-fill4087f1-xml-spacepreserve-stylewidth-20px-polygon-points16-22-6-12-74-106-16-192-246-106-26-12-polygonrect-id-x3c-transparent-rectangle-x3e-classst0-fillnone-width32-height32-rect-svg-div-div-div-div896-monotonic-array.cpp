class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()<=2)return true;
        int check=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])continue;
            if(check==-1){
                if(nums[i]>nums[i-1])check=1;//increasing
                else
                check=2;//decreasing
            }
            else{
                if(nums[i]>nums[i-1]&&check!=1)return false;
                if(nums[i]<nums[i-1]&&check!=2)return false;
            }
        }
        return true;
    }
};