//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int,int>>store;
        for(int i=0;i<n;i++)
        store.push_back({arr[i],dep[i]});
        sort(store.begin(),store.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int count=0;
        for(int i=0;i<n;i++){
            auto x=store[i];
            int s=x.first,e=x.second;
            if(!pq.empty()){
                int t=pq.top();
                if(s>t){//not overlap
                    while(!pq.empty()&&pq.top()<s)
                    pq.pop();
                }
                pq.push(e);
            }
            else{
                pq.push(e);
            }
            count = max(count, static_cast<int>(pq.size()));
        }
        return count;
    } 
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends