class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,mini=prices[0];
        for(int i=1;i<prices.size();i++){
            int val=prices[i]-mini;
            profit=max(profit,val);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};