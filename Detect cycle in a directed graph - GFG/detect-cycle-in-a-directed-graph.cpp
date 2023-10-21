//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int start,int vis[],int path[],vector<int> adj[]){
        vis[start]=1;
        path[start]=1;
        for(int x:adj[start]){
            if(!vis[x]){
                if(dfs(x,vis,path,adj))return true;
            }
            else if (path[x])return true;//as vis[x] and pathVis[x] both true
        }
        path[start]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int path[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
            if(dfs(i,vis,path,adj))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends