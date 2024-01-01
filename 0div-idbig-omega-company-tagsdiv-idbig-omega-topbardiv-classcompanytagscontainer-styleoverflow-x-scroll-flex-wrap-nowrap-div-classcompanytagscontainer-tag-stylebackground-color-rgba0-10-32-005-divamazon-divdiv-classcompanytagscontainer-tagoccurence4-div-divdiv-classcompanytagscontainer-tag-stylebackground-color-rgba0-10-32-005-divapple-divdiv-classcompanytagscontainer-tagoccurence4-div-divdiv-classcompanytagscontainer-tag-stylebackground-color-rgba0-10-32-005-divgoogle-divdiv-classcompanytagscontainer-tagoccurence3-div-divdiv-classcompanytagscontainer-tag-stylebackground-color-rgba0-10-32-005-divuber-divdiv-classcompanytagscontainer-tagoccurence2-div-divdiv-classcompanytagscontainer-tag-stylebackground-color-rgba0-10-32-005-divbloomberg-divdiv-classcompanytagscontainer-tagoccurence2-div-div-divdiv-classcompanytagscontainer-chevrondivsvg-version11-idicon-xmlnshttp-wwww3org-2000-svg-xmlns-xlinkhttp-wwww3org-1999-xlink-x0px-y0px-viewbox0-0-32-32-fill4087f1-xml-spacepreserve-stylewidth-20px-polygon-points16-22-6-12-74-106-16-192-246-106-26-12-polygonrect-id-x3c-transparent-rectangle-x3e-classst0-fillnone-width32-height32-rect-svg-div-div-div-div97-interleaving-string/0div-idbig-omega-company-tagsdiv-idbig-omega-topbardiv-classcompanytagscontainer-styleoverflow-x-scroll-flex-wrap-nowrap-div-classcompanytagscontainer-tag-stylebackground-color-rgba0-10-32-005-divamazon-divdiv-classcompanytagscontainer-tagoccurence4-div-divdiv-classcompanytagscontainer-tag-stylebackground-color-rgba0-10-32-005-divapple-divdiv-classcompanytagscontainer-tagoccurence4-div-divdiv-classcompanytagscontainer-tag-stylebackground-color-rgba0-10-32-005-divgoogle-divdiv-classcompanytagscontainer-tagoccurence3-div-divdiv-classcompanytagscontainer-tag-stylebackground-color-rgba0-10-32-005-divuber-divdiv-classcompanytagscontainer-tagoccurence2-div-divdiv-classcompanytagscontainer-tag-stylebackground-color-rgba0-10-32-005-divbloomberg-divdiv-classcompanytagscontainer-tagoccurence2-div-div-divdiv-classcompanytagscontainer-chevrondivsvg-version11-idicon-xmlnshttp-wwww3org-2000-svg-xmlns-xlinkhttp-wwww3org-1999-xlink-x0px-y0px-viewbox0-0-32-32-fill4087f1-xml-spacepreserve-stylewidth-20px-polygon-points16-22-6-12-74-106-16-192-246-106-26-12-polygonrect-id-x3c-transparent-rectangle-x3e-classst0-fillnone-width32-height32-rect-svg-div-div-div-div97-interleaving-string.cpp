class Solution {
private:
    bool helper(int i,int j,string s1,string s2,string s3,vector<vector<int>>&dp){
        if(i>=s1.length()&&j>=s2.length())return true;
        if(dp[i][j]!=-1)return dp[i][j];
        bool ans=false;
        if(i<s1.length()&&s3[i+j]==s1[i])
        ans=ans||helper(i+1,j,s1,s2,s3,dp);
        if(j<s2.length()&&s3[i+j]==s2[j])
        ans=ans||helper(i,j+1,s1,s2,s3,dp);
        return dp[i][j]=ans;        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length(),m=s2.length();
        if(n+m<s3.length())return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,s1,s2,s3,dp);
    }
};