class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long res=0,mask;int first=0,second=0;
        for(auto x:nums)
        res^=x;
        mask=res&(-1*res);
        for(auto x:nums){
            if((mask&x)!=0)
            first^=x;
            else
            second^=x;
        }
        return {first,second};
    }
};