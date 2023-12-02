//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    long long int count=0;
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[],long long low,long long mid,long long high){
        long long size=(high-low)+1,left=low,right=mid+1,i=0;
        long long temp[size];
        while(left<=mid&&right<=high){
            if(arr[left]<=arr[right]){
                temp[i++]=arr[left];left++;
            }
            else{
                temp[i++]=arr[right];right++;
                count+=(mid-left)+1;
            }
        }
        while(left<=mid)
            temp[i++]=arr[left++];
        
        while(right<=high)
        temp[i++]=arr[right++];
        for(i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
    }
    void mergeshort(long long arr[], long long low,long long high){
        if(low==high)return;
        long long mid=(low+high)/2;
        mergeshort(arr,low,mid);
        mergeshort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    long long int inversionCount(long long arr[], long long N)
    {
    
         mergeshort(arr,0,N-1);
         return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends