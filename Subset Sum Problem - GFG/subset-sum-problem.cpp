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
        vector<vector<int>>dp(arr.size(),vector<int>(sum,-1));
       return helper(0,0,sum,arr,dp);
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