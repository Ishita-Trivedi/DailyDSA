class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0,prev=0,next,curr=1,n=nums.size();
        if(n<=2)return 0;
        while(curr<n&&nums[prev]==nums[curr])
        curr++;
        if(curr>=n)return 0;
        next=curr;
        while(next<n){
            while(next<n&&nums[curr]==nums[next])next++;
            if(next>=n)break;
        if(nums[curr]>nums[prev]&&nums[curr]>nums[next])count++;//hill
        //valley
        else if(nums[curr]<nums[prev]&&nums[curr]<nums[next])count++;
        prev=curr;
        curr=next;
        next++;
        }
        return count;
    }
};