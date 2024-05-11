class Solution {
public:
    vector<vector<int>>psum;
    vector<int>dp;
    int helper(int i,string& s){
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int minSubs=s.length();
        for(int j=i;j>=0;j--){
            //check if valid j to i
            int currFreq=0;
            bool isPossible=true;
            for(int k=0;k<26;k++){
            int freq=psum[i][k]-((j-1>=0)?psum[j-1][k]:0);
            if(currFreq!=0&&freq!=0&&currFreq!=freq)isPossible=false;
            currFreq=max(currFreq,freq);
            }
            if(!isPossible)continue;
            minSubs=min(minSubs,1+helper(j-1,s));
        }
        return dp[i]=minSubs;
    }
    int minimumSubstringsInPartition(string s) {
        int n=s.length();
        dp=vector<int>(n+1,-1);
        psum=vector<vector<int>>(n+1,vector<int>(26,0));
        psum[0][s[0]-'a']=1;
        for(int i=1;i<n;i++){
            psum[i][s[i]-'a']++;
            for(int j=0;j<26;j++)
            psum[i][j]+=psum[i-1][j];
        }
        return helper(n-1,s);
    }
};