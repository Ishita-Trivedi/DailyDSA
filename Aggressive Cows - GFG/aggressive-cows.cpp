//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool possible(vector<int>stalls,int cows,int dist){
        int cc=1,last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(abs(stalls[i]-last)>=dist){
                cc++;
                last=stalls[i];
            }
        }
        return cc>=cows;//cows placed is cc
    }
    int bsearch(vector<int> &stalls,int cows){
        sort(stalls.begin(),stalls.end());
        int low=1,high=*max_element(stalls.begin(),stalls.end())-*min_element(stalls.begin(),stalls.end()),mid;
        while(low<=high){
            int mid=high-(high-low)/2;
            if(possible(stalls,cows,mid))low=mid+1;
            else
            high=mid-1;
        }
        return high;
    }
    int solve(int n, int k, vector<int> &stalls) {
        return bsearch(stalls,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends