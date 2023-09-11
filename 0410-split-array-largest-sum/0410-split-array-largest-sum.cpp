class Solution {
public:
    int possible(vector<int>& nums,int limit){
        int stu=1,ps=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+ps>limit){
                stu++;
                ps=nums[i];
            }
            else
            ps+=nums[i];
        }
        return stu;
    }
    int bsearch(int k,vector<int>& nums){
        long long low=*max_element(nums.begin(),nums.end()),high=accumulate(nums.begin(),nums.end(),0),mid;
        while(low<=high){
            mid=high-(high-low)/2;
            int allocated=possible(nums,mid);
            if(allocated<=k)high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return bsearch(k,nums);
    }
};