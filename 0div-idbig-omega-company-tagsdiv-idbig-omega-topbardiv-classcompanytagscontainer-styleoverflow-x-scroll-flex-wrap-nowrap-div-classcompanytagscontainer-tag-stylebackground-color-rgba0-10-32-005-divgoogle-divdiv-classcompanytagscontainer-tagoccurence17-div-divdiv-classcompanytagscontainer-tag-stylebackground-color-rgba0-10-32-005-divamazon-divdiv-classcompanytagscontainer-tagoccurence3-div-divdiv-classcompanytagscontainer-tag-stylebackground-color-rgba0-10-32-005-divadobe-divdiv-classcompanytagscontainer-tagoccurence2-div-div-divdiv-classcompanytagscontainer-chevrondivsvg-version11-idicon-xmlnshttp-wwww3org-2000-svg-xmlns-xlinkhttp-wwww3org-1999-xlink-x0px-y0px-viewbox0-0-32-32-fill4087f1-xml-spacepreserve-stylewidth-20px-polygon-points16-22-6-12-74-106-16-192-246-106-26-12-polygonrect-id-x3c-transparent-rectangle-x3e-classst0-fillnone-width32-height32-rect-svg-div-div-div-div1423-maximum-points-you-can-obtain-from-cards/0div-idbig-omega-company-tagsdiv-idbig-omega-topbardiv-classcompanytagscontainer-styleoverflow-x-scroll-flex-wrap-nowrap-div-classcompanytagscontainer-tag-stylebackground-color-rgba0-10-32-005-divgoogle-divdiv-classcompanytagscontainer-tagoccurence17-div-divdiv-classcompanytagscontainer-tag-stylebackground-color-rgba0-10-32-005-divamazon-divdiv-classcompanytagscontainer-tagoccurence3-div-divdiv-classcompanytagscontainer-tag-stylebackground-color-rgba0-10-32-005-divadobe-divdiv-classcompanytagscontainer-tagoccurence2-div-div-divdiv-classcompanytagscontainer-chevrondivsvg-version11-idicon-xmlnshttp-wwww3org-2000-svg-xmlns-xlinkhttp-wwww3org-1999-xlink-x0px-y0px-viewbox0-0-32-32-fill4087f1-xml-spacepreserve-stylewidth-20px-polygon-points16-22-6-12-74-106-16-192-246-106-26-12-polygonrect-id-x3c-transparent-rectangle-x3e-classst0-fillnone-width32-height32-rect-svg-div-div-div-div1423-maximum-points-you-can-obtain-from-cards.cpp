class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     //instead of included we create window of excluded
     int ws=0,we=cardPoints.size()-1,sum=0,maxSum=0;
     while(ws<k){
        sum+=cardPoints[ws];ws++;
     }
     ws--;
     maxSum=sum;
     while(ws>=0){
        sum+=cardPoints[we];we--;
        sum-=cardPoints[ws];
        maxSum=max(sum,maxSum);
        ws--;
     }
     return maxSum;
    }
};