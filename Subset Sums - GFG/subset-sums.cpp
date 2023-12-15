//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private:
    void helper(int i,vector<int>&arr,long long sum,vector<int>&ans){
        if(i>=arr.size()){
            ans.push_back(sum);return;
        }
       
        helper(i+1,arr,sum,ans);
        helper(i+1,arr,sum+arr[i],ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
         vector<int>ans;
         helper(0,arr,0,ans);
         return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends