//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool possible(int arr[], int N,int cap, int D){
        int days=0,c=0;
        for(int i=0;i<N;i++){
            if(c+arr[i]<=cap)
            c+=arr[i];
            else if(arr[i]<=cap){
                c=arr[i];days++;
            }
            else
            return false;
        }
        return days+1<=D;
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        int l,h,mid;
        l=*min_element(arr,arr+N);
        h=accumulate(arr,arr+N,0);
        while(l<=h){
            mid=(l+h)/2;
            bool c=possible(arr,N,mid,D);
            if(c)h=mid-1;
            else
            l=mid+1;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends