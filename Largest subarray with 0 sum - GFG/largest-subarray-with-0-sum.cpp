//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        //doing prefix sum
        unordered_map<long long,int>mp;
        long long sum=0;
        mp[0]=-1;
        int maxLen=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(mp.find(sum)==mp.end())
            mp[sum]=i;
            else
            maxLen=max(maxLen,i-mp[sum]);
        }
        
        return max(maxLen,0);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends