//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     //using flyod warshall algo
  vector<vector<int>> matrix(n, vector<int>(n, 1e9));
    for(int i=0;i<n;i++)//diagonals
    matrix[i][i]=0;
    for(auto vec:edges){//UG to DG conversion
        int u=vec[0],v=vec[1],wt=vec[2];
        matrix[u][v]=wt;matrix[v][u]=wt;
    }
    //FWA
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    int max_count=n,node=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i==j)continue;//as this would always be zero
            if(matrix[i][j]<=distanceThreshold)count++;
        }
        if(count<=max_count){max_count=count;node=i;}
    }
    return node;
 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends