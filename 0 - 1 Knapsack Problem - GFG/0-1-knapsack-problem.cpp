//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int>prev(W+1,0);
        for(int i=1;i<n+1;i++){
            vector<int>curr(W+1,0);
            for(int weight=1;weight<W+1;weight++){
                int take=0;
                if(wt[i-1]<=weight)
                take=val[i-1]+prev[weight-wt[i-1]];
                int ntake=prev[weight];
                curr[weight]=max(take,ntake);
            }
            prev=curr;
        }
        
       return prev[W];
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