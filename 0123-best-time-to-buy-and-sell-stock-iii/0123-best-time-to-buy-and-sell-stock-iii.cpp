class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>prev(2, vector<int>(3, 0));
        vector<vector<int>>curr(2, vector<int>(3, 0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                int take=0,ntake=0;
                if(buy){
                    take=-prices[i]+prev[0][count];
                    ntake=0+prev[1][count];
                }
                else{//sell
                take=+prices[i]+prev[1][count-1];
                ntake=0+prev[0][count];
                }
                curr[buy][count]=max(take,ntake);
                }
                prev=curr;
            }
        }
        return prev[1][2];
    }
};