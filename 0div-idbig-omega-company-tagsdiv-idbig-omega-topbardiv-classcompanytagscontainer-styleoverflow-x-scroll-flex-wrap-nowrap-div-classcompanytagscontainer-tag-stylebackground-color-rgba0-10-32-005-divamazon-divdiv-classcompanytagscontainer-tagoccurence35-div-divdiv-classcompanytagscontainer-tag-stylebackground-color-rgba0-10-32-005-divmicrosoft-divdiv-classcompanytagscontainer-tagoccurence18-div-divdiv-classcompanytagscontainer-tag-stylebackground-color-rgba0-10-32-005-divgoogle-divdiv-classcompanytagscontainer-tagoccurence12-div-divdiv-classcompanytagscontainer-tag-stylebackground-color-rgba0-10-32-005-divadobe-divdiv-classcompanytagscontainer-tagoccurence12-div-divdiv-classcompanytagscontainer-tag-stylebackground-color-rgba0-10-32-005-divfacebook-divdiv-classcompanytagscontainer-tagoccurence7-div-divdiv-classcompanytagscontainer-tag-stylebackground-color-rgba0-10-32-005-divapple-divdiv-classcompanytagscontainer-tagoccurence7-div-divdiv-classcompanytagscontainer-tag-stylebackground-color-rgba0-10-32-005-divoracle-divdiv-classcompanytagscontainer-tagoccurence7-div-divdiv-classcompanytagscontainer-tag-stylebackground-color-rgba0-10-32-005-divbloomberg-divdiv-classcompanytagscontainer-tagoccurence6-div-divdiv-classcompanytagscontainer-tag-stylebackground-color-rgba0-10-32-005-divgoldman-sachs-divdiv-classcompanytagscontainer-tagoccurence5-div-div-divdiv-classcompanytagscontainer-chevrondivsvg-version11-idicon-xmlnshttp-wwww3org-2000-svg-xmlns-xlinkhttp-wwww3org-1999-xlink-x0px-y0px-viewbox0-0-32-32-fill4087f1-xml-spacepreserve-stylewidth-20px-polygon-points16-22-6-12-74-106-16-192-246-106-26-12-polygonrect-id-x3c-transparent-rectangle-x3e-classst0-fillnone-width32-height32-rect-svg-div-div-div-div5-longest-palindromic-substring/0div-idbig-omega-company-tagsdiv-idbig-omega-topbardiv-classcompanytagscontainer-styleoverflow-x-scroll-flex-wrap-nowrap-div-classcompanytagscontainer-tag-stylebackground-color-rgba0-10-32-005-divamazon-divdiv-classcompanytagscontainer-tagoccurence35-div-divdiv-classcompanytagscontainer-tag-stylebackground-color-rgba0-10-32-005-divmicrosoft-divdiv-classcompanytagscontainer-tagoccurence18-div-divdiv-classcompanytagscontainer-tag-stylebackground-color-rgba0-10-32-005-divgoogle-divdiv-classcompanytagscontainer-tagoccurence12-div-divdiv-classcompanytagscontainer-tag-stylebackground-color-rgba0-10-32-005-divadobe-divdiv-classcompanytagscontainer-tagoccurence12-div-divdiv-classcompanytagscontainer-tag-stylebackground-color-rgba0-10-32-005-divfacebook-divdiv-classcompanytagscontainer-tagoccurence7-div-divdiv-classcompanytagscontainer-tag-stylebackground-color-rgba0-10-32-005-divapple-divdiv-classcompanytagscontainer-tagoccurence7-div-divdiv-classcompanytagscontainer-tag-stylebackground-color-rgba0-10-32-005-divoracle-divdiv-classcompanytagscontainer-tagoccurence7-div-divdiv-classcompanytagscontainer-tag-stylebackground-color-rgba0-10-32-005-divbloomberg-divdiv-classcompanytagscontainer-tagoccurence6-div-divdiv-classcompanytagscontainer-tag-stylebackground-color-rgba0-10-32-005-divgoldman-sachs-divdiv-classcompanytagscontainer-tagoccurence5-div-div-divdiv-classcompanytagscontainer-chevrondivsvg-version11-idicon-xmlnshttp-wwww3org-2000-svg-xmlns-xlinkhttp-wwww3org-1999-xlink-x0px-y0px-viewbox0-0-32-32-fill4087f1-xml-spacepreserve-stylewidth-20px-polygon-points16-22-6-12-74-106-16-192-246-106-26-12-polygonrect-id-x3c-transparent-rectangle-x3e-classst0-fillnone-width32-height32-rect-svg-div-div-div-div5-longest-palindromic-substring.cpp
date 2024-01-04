class Solution {
private:
    bool check(int i,int j,string& s,vector<vector<int>>&dp){
        if(i>=j)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])
        return dp[i][j]=check(i+1,j-1,s,dp);
        return dp[i][j]=false;
    }
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int len=1,index=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s,dp)){
                    if(j-i+1>len){
                        len=j-i+1;
                        index=i;
                    }
                }
            }
        }
        return s.substr(index,len);
    }
};