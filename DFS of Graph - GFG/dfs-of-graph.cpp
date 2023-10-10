//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void traverse(int start,vector<int>&dfs,int vis[],vector<int> adj[]){
        dfs.push_back(start);vis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it])
            traverse(it,dfs,vis,adj);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>dfs;
        int vis[V]={0};
        traverse(0,dfs,vis,adj);
        return dfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends