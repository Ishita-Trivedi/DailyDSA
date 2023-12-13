class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxi=0;
        for(int x:nums){
            if(x==1)count++;
            else{
                maxi=max(maxi,count);
                count=0;
            }
        }
        return max(count,maxi);
    }
};