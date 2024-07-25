class Solution {
public:
    void merge(int l,int mid,int r,vector<int>&nums){
        int i=l,j=mid+1;
        vector<int>temp;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j])
            temp.push_back(nums[i++]);
            else
            temp.push_back(nums[j++]);
        }
        while(i<=mid)
         temp.push_back(nums[i++]);
          while(j<=r)
         temp.push_back(nums[j++]);
         for(int i=l;i<=r;i++)
         nums[i]=temp[i-l];
    }
    void mergeSort(int l,int r,vector<int>&nums){
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(l,mid,nums);
            mergeSort(mid+1,r,nums);
            merge(l,mid,r,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int>arr(nums.begin(),nums.end());
        mergeSort(0,nums.size()-1,arr);
        return arr;
    }
};