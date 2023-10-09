class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0,maxi=INT_MIN;
        for(int i=0;i<k;i++)
        sum+=nums[i];
        maxi=max(maxi,sum/(double)k);
        for(int we=k;we<nums.size();we++){
            sum+=nums[we];
            sum-=nums[we-k];
            maxi=max(maxi,sum/(double)k);
        }
        return maxi;
    }
};