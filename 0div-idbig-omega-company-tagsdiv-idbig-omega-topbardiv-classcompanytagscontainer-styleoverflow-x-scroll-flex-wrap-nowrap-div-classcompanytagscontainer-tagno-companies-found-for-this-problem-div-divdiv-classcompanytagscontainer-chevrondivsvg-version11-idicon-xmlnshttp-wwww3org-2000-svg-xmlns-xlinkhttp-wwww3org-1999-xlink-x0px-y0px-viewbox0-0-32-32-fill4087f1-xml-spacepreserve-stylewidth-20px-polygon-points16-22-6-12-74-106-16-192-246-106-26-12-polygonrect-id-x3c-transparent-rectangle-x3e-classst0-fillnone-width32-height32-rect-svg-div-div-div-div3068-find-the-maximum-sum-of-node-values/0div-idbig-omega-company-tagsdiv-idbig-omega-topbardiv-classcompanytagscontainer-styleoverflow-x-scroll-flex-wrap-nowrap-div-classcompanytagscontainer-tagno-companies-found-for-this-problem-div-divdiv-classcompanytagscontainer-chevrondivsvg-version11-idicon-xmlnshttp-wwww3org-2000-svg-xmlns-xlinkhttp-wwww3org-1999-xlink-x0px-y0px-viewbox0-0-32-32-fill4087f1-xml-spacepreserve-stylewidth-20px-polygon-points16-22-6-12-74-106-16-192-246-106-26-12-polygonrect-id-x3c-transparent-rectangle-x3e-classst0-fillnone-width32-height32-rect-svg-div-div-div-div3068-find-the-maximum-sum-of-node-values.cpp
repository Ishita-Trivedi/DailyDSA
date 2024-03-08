typedef long long ll;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
     ll sum=0,cnt=0,mini=INT_MAX;
     for(auto el:nums){
         if((el^k)>el){
             sum+=el^k;
             mini=min(mini,(ll)(el^k)-el);
             cnt++;
         }
         else{
             sum+=el;
             mini=min(mini,(ll)el-(el^k));
         }
     }
     if(cnt%2==0)return sum;
     return sum-mini;
    }
};