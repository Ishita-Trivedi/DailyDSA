class Solution {
public:
    map<string,int>mp;
    vector<int>dp;
    int helper(int i,string s,int n){
        if(i>=s.length())return 0;
        if(dp[i]!=-1)return dp[i];
        int mini=1e9;
        string current="";
        for(int k=i;k<n;k++){
            current+=s[k];
            if(mp.find(current)!=mp.end()){
                mini=min(mini,helper(k+1,s,n));
            }
        }
        mini=min(mini,1+helper(i+1,s,n));
        return dp[i]=mini;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        dp.resize(n+1,-1);
        for(string st:dictionary)mp[st]++;
        return helper(0,s,n);
    }
};