//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void traverse(int start,int visited[],vector<int>adj[],vector<int>&dfs){
        visited[start]=1;
        dfs.push_back(start);
        for(auto it:adj[start]){
            if(!visited[it])
            traverse(it,visited,adj,dfs);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>dfs;
        int visited[V]={0};
        traverse(0,visited,adj,dfs);
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