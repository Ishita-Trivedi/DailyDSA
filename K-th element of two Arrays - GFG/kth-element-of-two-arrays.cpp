//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)return kthElement(arr2,arr1,m,n,k);//n<k<m
        int l=max(0,k-m),h=min(k,n),mid1,mid2,l1,l2,r1,r2;
        while(l<=h){
            mid1=(h+l)>>1;
            mid2=k-mid1;
            l1=INT_MIN;l2=INT_MIN;
            r1=INT_MAX;r2=INT_MAX;
            if(mid1<n)r1=arr1[mid1];
            if(mid2<m)r2=arr2[mid2];
            if(mid1-1>=0)l1=arr1[mid1-1];
            if(mid2-1>=0)l2=arr2[mid2-1];
            if(l1<=r2&&l2<=r1){
                return max(l1,l2);
            }
            if(l1>r2)h=mid1-1;
            else
            l=mid1+1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends