class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),maxi=INT_MIN;
        vector<int>ans(3,0),lhs(n,0),rhs(n,0);
        vector<int>prefixsum(n+1,0);
        //calcuate 1 indexed prefix sum
        for(int i=1;i<=n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i-1];
        }
        int maxilhs=prefixsum[k]-prefixsum[0];
        for(int i=k;i<n;i++){
            int current=prefixsum[i+1]-prefixsum[i-k+1];
            if(current>maxilhs){
                maxilhs=current;
                lhs[i]=i-k+1;//0-indexed
            }
            else
            lhs[i]=lhs[i-1];
        }
        int maxsumrhs=prefixsum[n]-prefixsum[n-k];
        rhs[n-k]=n-k;
        for(int i=n-k-1;i>=0;i--){
            int current=prefixsum[i+k]-prefixsum[i];
            if(current>=maxsumrhs){
                maxsumrhs=current;
                rhs[i]=i;//0-indexed
            }
            else
            rhs[i]=rhs[i+1];
        }
        //calcualte the result
        for(int i=k;i<=n-2*k;i++){
           int left=lhs[i-1],right=rhs[i+k],
           sum=prefixsum[left+k]-prefixsum[left]+
               prefixsum[i+k]-prefixsum[i]+
               prefixsum[right+k]-prefixsum[right];
            if(sum>maxi){
               maxi=sum;
                ans={left,i,right};
            }
        }
        return ans;
    }
};