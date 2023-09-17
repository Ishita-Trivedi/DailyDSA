class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int l = 0; 
        int r = nums.size()-1;
        int ans = 0;
       l=nums.size()/2-1;
        while (0 <= l) {
            if (nums[l] < nums[r]) {
                ans += 2;
                l--;
                r--;
            }
            else {
                l--;
            }
        }
        return nums.size() - ans;
    }
};