//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod = static_cast<int>(1e9 + 7);
	int helper(int i,int target,int n,int arr[],vector<vector<int>>&dp){
	    if(i>=n){
	        if(target==0)
	        return 1;
	        return 0;
	    }
	    if(dp[i][target]!=-1)return dp[i][target];
	    int take = 0;
        if (target - arr[i] >= 0)
        take=helper(i+1,target-arr[i],n,arr,dp)%mod;
	    int ntake=helper(i+1,target,n,arr,dp)%mod;
	    return dp[i][target]=(take+ntake)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(0,sum,n,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends