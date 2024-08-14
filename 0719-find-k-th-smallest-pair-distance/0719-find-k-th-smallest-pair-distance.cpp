class Solution {
public:
    int countPairs(vector<int>&nums,int target){
        int l=0,count=0,n=nums.size();
        for(int r=1;r<n;r++){
            while(nums[r]-nums[l]>target)
            l++;
            count+=r-l;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,n=nums.size(),h=nums[n-1]-nums[0];
        while(l<h){
            int mid=l+(h-l)/2;
            int cnt=countPairs(nums,mid);
            if(cnt<k)l=mid+1;
            else
            h=mid;
        }
        return l;
    }
};