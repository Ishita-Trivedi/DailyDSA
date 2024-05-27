class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i||i+1){
            int ub=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            if(ub==nums.size())return -1;
            int els=nums.size()-ub;
            if(i==els)return i;
            i++;
        }
        return -1;
    }
};