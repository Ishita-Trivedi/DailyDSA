class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int s=0;
        for(auto vec:matches)
        {s=max(s,vec[0]);s=max(s,vec[1]);}
        vector<int>win(s+1,0);
        vector<int>lost(s+1,0);
        vector<int>winners,losers;
        for(auto vec:matches){
            win[vec[0]]++;lost[vec[1]]++;
        }
        for(int i=1;i<=s;i++){
            if(win[i]>=1&&lost[i]==0)winners.push_back(i);
            else if(lost[i]==1)losers.push_back(i);
        }
        return {winners,losers};
    }
};