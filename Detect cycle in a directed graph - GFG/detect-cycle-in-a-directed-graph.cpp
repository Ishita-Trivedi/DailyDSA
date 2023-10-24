//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph using topo Sort
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>topo;
        int indeg[V]={0};
        for(int i=0;i<V;i++){
            for(int x:adj[i])
            indeg[x]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int n=q.front();q.pop();
            topo.push_back(n);
            for(int x:adj[n]){
                if(--indeg[x]==0)
                q.push(x);
            }
        }
        return !(topo.size()==V);//if equal to V then no cycle so false
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