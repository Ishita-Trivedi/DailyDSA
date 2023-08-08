//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod = static_cast<int>(1e9 + 7);
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<int>prev(sum + 1, 0);
	    prev[0]=1;
    for (int i = 1; i <=n; i++) {
        vector<int>curr(sum + 1, 0);
        for (int target = 0; target <= sum; target++) { 
            int take = 0;
            if (target - arr[i-1] >= 0)
                take = (prev[target - arr[i-1]]) % mod;
            int ntake = (prev[target]) % mod;
            curr[target] = (take + ntake) % mod;
            
        }
        prev=curr;
    }
    return prev[sum];
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