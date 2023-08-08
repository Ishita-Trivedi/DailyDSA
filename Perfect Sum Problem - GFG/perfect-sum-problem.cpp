//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod = static_cast<int>(1e9 + 7);
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
	    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for (int i = 1; i <=n; i++) {
        for (int target = 0; target <= sum; target++) { // Add increment statement
           
            int take = 0;
            if (target - arr[i-1] >= 0)
                take = (dp[i - 1][target - arr[i-1]]) % mod;
            int ntake = (dp[i - 1][target]) % mod;
            dp[i][target] = (take + ntake) % mod;
            
        }
    }
    return dp[n ][sum];
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