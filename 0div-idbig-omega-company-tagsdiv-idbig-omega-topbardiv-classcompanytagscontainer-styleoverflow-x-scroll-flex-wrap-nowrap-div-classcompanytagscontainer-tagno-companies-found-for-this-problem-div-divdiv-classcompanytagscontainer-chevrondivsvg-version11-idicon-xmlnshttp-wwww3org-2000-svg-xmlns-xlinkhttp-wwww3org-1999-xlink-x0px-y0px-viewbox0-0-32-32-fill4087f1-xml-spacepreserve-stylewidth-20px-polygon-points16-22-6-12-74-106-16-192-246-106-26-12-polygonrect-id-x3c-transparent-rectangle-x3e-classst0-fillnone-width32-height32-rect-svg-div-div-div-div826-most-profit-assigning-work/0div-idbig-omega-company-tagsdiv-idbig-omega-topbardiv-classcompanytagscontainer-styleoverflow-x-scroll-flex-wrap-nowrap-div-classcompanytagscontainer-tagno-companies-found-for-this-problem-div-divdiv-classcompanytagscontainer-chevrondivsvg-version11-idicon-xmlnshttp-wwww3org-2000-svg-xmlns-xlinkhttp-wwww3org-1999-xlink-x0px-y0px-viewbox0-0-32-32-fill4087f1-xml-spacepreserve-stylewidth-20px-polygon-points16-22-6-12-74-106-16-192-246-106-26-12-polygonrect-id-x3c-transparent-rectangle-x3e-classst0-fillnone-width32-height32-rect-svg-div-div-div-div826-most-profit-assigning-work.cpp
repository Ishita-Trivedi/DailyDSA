class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>vec;
        int n=profit.size(),sum=0;
        for(int i=0;i<n;i++)
        vec.push_back({difficulty[i],profit[i]});
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            int d=vec[i].first,p=vec[i].second;
            difficulty[i]=d;
            profit[i]=p;
        }
        int maxi=profit[0];
        for(int i=1;i<n;i++){
            maxi=max(profit[i],maxi);
            profit[i]=maxi;
        }
        for(auto x:worker){
            int idx=upper_bound(difficulty.begin(),difficulty.end(),x)-difficulty.begin();
            idx--;
            if(idx>=0){
                sum+=profit[idx];
            }
        }
        return sum;
    }
};