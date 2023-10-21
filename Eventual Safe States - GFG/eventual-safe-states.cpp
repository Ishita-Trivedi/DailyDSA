//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool dfs(int start,int vis[],int path[],int check[],vector<int> adj[]){
        vis[start]=1;path[start]=1;
        for(int x:adj[start]){
            if(!vis[x]){
                if(!dfs(x,vis,path,check,adj))return false;
            }
            else if(path[x]) return false;//had an outgoing and came back from it so path =1
        }
        
        check[start]=1;path[start]=0;
        return true;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int check[V]={0};int vis[V]={0};int path[V]={0};
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
               bool t= dfs(i,vis,path,check,adj);
            }
        }
        for(int i=0;i<V;i++){//prevents sorting of the elements
            if(check[i]==1)
            ans.push_back(i);
        }
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