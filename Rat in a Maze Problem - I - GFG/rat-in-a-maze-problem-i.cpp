//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
        bool isValid(int i,int j,int n,vector<vector<int>> &m){
            if(i<0||j<0||i>=n||j>=n)return false;
            return m[i][j]==1;
        }
        void helper(int i,int j,int n,string path,vector<string>&ans,vector<vector<int>> &m)
        {
            if(i>=n||j>=n)return;
            if(i==n-1&&j==n-1){
                ans.push_back(path);
                return;
            }
            if(!m[i][j])return;
            m[i][j]=0;
            if(isValid(i+1,j,n,m))
            helper(i+1,j,n,path+"D",ans,m);
            if(isValid(i,j+1,n,m))
            helper(i,j+1,n,path+"R",ans,m);
            if(isValid(i,j-1,n,m))
            helper(i,j-1,n,path+"L",ans,m);
            if(isValid(i-1,j,n,m))
            helper(i-1,j,n,path+"U",ans,m);
            m[i][j]=1;
        }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
       if(m[n-1][n-1]==0||m[0][0]==0)return {"-1"};
       vector<string>ans;
       helper(0,0,n,"",ans,m);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends