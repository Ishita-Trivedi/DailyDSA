class Solution {
private:
    bool palindrome(long long number){
        string s=to_string(number);
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-1-i])return false;
        }
        return true;
    }
public:
    long long minimumCost(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       long long n=nums.size(),l,r,cost=LLONG_MAX;
       l=nums[n/2];r=l;
       while(l>0&&!palindrome(l))l--;
       while(r<1e10&&!palindrome(r))r++;
       for(int x:{l,r}){
           long long sum=0;
           for(int ele:nums)
           sum+=abs(ele-x);
           cost=min(cost,sum);
       }
       return cost;       
    }
};