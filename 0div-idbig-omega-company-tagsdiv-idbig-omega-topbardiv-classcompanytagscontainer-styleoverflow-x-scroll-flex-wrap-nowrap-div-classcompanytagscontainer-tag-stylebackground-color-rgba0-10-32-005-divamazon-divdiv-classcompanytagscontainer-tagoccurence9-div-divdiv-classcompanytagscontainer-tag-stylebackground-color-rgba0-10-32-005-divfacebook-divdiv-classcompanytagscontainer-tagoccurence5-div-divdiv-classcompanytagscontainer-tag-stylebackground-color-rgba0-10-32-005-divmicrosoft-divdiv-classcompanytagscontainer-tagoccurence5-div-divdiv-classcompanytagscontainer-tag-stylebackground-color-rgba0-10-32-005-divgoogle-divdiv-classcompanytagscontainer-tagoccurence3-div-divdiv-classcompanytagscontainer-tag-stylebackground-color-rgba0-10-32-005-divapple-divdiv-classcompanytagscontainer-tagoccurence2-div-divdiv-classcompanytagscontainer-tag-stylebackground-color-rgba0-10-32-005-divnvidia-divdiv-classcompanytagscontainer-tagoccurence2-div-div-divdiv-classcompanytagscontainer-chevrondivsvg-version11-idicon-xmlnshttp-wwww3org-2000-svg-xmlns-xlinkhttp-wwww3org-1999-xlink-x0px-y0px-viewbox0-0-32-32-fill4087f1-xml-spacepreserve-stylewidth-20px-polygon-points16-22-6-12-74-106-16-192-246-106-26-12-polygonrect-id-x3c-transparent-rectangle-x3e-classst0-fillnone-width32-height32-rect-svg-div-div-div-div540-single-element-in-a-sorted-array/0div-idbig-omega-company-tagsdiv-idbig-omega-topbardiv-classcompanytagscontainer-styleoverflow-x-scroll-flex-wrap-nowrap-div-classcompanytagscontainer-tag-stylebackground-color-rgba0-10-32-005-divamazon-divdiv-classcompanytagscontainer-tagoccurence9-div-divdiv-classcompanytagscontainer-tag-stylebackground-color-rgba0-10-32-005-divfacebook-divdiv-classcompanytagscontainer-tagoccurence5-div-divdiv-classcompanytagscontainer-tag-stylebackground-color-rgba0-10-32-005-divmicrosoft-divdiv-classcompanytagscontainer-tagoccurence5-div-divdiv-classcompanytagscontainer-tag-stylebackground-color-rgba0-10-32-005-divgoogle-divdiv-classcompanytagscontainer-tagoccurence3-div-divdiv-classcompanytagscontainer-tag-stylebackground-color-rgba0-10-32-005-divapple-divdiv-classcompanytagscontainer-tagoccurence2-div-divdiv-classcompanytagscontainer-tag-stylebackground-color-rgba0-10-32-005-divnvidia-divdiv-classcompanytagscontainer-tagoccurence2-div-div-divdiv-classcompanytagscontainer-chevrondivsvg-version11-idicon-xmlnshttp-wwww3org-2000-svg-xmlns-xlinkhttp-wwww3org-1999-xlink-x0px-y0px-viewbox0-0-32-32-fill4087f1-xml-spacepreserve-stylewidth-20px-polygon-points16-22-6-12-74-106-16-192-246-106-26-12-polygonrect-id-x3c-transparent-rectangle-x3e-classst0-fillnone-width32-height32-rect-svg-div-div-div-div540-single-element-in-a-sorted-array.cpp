class Solution {
private:
    int move(vector<int>& nums,int mid){
        if(mid==0&&nums[mid+1]!=nums[mid])return 1;
        if(mid==nums.size()-1&&nums[mid-1]!=nums[mid])return 1;
        if(nums[mid-1]!=nums[mid]&&nums[mid+1]!=nums[mid])return 1;
        if(nums[mid-1]==nums[mid]){
            if(mid%2==1)return 0;//left part->move right
            else
            return 2;//right part->move left
        }
        else{//nums[mid]==nums[mid+1]
            if(mid%2==0)return 0;//left part->move right
            else
            return 2;//right part->move left
        }
        return -1;
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(),low=0,high=n-1,mid;
        if(n==1)return nums[0];
        while(low<=high){
            mid=high-(high-low)/2;
            int m=move(nums,mid);
            if(m==1)return nums[mid];
            else if(m==0)low=mid+1;
            else
            high=mid-1;
        }
        return -1;
    }
};