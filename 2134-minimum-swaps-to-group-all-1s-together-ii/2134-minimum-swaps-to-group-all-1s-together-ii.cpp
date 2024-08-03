class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),
        cnt1=count(nums.begin(),nums.end(),1),ws=0,maxOnes=0,ones=0;
        for(int i=0;i<cnt1;i++)
        ones+=(nums[i]==1);
        maxOnes=max(maxOnes,ones);
        for(int i=cnt1;i<n+cnt1;i++){
            ones-=nums[(i-cnt1)%n];
            ones+=nums[i%n];
            maxOnes=max(maxOnes,ones);
        }
        return cnt1-maxOnes;
    }
};