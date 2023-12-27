class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum=0,maxTime=neededTime[0];
        char curr=colors[0];
        for(int i=1;i<colors.size();i++){
            if(curr==colors[i]){
                if(neededTime[i]>maxTime){
                    sum+=maxTime;
                    maxTime=neededTime[i];
                }
                else
                sum+=neededTime[i];
            }
            else{
                curr=colors[i];
                maxTime=neededTime[i];
            }
        }
        return sum;
    }
};