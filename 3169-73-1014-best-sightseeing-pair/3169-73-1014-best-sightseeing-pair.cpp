class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxi=0,maxrhs=INT_MIN;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int curr=values[i]+i,otherval=values[i]-i;
            if(maxrhs!=INT_MIN){
                maxi=max(maxi,curr+maxrhs);
            }
            maxrhs=max(maxrhs,otherval);
        }
        return maxi;
    }
};