class Solution {
public:
    bool possible(int x, int threshold,vector<int>& nums){
        int result=0;
        for(int i=0;i<nums.size();i++){
            result+=ceil((double)nums[i]/(double)x);
        }
        return result<=threshold;
    }
    int bsearch(vector<int>& nums, int threshold){
        int low=1,high=*max_element(nums.begin(),nums.end()),mid;
        while(low<=high){
            mid=(low+high)/2;
            if(possible(mid,threshold,nums))high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        return bsearch(nums, threshold);
    }
};