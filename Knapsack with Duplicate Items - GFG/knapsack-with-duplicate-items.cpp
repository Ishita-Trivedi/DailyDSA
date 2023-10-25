//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i,int w,int val[],int wt[],vector<vector<int>>&dp){
        if(i<0||w<0)return 0;
        if(dp[i][w]!=-1)return dp[i][w];
        int take=0,ntake=0;
        if(wt[i]<=w)
        take=val[i]+helper(i,w-wt[i],val,wt,dp);
        ntake=helper(i-1,w,val,wt,dp);
        return dp[i][w]=max(take,ntake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        helper(N-1,W,val,wt,dp);
        return dp[N-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends