class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
         vector<int>ans,lhs(n,0),rhs(n,0);
         for(int i=1;i<n;i++){
            if(security[i-1]>=security[i])
            lhs[i]+=lhs[i-1]+1;
         }
         for(int i=n-2;i>=0;i--){
            if(security[i+1]>=security[i])
            rhs[i]+=rhs[i+1]+1;
         }
         for(int i=0;i<n;i++){
            if(lhs[i]>=time&&rhs[i]>=time)
            ans.push_back(i);
         }
         return ans;
    }
};