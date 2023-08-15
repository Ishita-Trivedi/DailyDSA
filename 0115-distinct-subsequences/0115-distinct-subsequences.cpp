class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length(),M=1e9+7;;
       vector<int>prev(m + 1, 0);
         // Initialize the first column with 1s
         prev[0]=1;
        for(int i=1;i<n+1;i++){
            vector<int>curr(m + 1, 0);
            curr[0]=1;
            for(int j=1;j<m+1;j++){
            int take = 0, ntake = 0;
            if (s[i-1] == t[j-1])
            take = prev[j-1];
            ntake =prev[j];
            curr[j] = (take + ntake)%M;
            }
            prev=curr;
        }
        return prev[m]%M;
    }
};
