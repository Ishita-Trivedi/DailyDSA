//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool detect(int start,int parent,int vis[],vector<int>adj[]){
        vis[start]=1;
        for(int adjNode:adj[start]){
            if(!vis[adjNode]){
                if(detect(adjNode,start,vis,adj))return true;
            }
            else if(parent!=adjNode)return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        //since it has connected components so we need to traverse atleast once
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,-1,vis,adj))return true;
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends