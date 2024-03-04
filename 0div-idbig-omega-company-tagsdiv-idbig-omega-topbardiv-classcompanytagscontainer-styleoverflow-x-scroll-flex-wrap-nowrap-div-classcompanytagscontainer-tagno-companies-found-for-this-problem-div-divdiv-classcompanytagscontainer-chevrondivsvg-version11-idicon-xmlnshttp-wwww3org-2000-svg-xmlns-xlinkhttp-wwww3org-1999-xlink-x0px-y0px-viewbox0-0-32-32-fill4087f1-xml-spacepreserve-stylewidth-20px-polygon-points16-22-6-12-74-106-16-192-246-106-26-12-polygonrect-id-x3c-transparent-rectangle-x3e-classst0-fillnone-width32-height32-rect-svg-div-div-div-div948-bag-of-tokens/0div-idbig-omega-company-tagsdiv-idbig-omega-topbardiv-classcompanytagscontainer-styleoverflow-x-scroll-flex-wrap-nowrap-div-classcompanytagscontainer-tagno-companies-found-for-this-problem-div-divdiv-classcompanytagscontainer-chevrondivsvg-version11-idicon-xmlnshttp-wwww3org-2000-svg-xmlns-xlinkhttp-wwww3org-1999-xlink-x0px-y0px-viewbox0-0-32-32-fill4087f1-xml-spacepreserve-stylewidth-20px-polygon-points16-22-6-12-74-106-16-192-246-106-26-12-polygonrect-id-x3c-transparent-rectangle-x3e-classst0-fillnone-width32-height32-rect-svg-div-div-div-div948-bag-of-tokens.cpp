class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxi=0,score=0,i=0,j=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
            }
            else if(score>=1){
                power+=tokens[j];
                score--;
                j--;
            }
            else
            break;
            maxi=max(maxi,score);
        }
        return maxi;
    }
};