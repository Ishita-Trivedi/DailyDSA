class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>hash(nums.size());
        vector<int>lis(nums.size(),1);
        int maxi=0,ind=0;
        for(int i=1;i<nums.size();i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if((1+lis[j])>lis[i]){
                        lis[i]=1+lis[j];
                        hash[i]=j;
                    }
                }
            }
            if(lis[i]>maxi){
                maxi=lis[i];ind=i;
            }
        }
        ans.push_back(nums[ind]);
        while(hash[ind]!=ind){
            ind=hash[ind];
            ans.push_back(nums[ind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};