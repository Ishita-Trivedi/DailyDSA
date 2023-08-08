//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(int i,int sum,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(sum==target)return true;
        if(i>=arr.size())return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool take=helper(i+1,sum+arr[i],target,arr,dp);
        bool ntake=helper(i+1,sum,target,arr,dp);
        return dp[i][sum]=take||ntake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>>dp(arr.size()+1,vector<int>(sum+1,0));
        for(int i=0;i<arr.size()+1;i++)
        dp[i][0]=1;
        dp[0][0]=1;//empty and sum=0
        for(int i=1;i<arr.size()+1;i++){
            for(int target=1;target<sum+1;target++){
                bool take=0;
               if(target-arr[i-1]>=0)
               take=dp[i-1][target-arr[i-1]];
               bool ntake=dp[i-1][target];
               dp[i][target]=take||ntake;
            }
        }
       return dp[arr.size()][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends