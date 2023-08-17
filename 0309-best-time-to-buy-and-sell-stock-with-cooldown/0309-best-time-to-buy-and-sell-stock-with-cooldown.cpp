class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // if(i+2<=prices.size()) for this n+2 else last case not included::wrong answer
        vector<int>prev1(2,0);
        vector<int>prev2(2,0);
        vector<int>curr(2,0);
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int take=0,ntake=0;
                if(buy){
                    take=-prices[i]+prev1[0];
                    ntake=0+prev1[1];
                }
                else{//sell
                    take=+prices[i]+prev2[1];
                    ntake=0+prev1[0];
                }
                curr[buy]=max(take,ntake);
            }
            prev2=prev1;
            prev1=curr;
        }
        return curr[1];
    }
};