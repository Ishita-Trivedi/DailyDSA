//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool bfs(queue<int>&q,vector<int>&vis, vector<int>adj[]){
        while(!q.empty()){
            int n=q.front();q.pop();
            for(int x:adj[n]){
                if(vis[x]==-1){
                    vis[x]=!vis[n];q.push(x);
                }
                else if(vis[x]==vis[n])return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>vis(V,-1);
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            q.push(i);vis[i]=0;
	            if(!bfs(q,vis,adj))return false;
	        }
	    }
	    return true;
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends