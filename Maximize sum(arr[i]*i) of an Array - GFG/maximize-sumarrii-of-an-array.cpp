//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int mod=1000000000+7;
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        long long  sum=0;
        for(long long  i=0;i<n;i++){
            a[i]%=mod;
            long long  val=i%mod;
            sum+=(a[i]*val*1LL)%mod;
            sum%=mod;
        }
        return static_cast<int>(sum%mod);
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends