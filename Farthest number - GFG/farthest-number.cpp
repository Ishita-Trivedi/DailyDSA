//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
        int mini[N];
        vector<int>store;
        mini[N-1]=N-1;
        for(int i=N-2;i>=0;i--){
            if(Arr[i]<Arr[mini[i+1]])
            mini[i]=i;
            else
            mini[i]=mini[i+1];
        }

        for(int i=0;i<N;i++){
            int l=i+1,h=N-1,mid,ans=-1;
            while(l<=h){
                mid=(l+h)/2;
                if(Arr[mini[mid]]<Arr[i]){
                    ans=mini[mid];
                    l=mid+1;
                }
                else
                h=mid-1;
            }
            store.push_back(ans);
        }
        return store;
    }
};

//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}
// } Driver Code Ends