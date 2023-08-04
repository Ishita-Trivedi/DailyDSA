class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total=0,curr=0;
        total=accumulate(nums.begin(),nums.end(),total);
        for(int i=0;i<nums.size();i++){
            cout<<"ind "<<i<<" "<<total<<" "<<curr<<endl;
            if(curr==(total-curr-nums[i]))return i;
            curr+=nums[i];
        }
        return -1;
    }
};