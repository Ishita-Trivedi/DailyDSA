//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int i,int curr,int W,int wt[],int val[],int n,vector<vector<int>>&dp){
        if(i>=n)return 0;
        if(dp[i][curr]!=-1)return dp[i][curr];
        int take=0;
        if((curr+wt[i])<=W)
        take=val[i]+helper(i+1,curr+wt[i],W,wt,val,n,dp);
        int ntake=helper(i+1,curr,W,wt,val,n,dp);
        return dp[i][curr]=max(take,ntake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        for(int i=1;i<n+1;i++){
            for(int weight=1;weight<W+1;weight++){
                int take=0;
                if(wt[i-1]<=weight)
                take=val[i-1]+dp[i-1][weight-wt[i-1]];
                int ntake=dp[i-1][weight];
                dp[i][weight]=max(take,ntake);
            }
        }
        
       return dp[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends