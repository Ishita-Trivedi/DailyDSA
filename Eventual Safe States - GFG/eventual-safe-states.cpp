//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool dfs(int start,int vis[],int path[],vector<int> adj[],vector<int>&ans){
        vis[start]=1;path[start]=1;
        for(int x:adj[start]){
            if(!vis[x]){
                if(!dfs(x,vis,path,adj,ans))return false;
            }
            else if(path[x]) return false;
        }
        ans.push_back(start);path[start]=0;
        return true;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;int vis[V]={0};int path[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
               bool t= dfs(i,vis,path,adj,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends