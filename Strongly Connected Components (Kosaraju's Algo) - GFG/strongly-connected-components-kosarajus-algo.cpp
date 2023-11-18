//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	void dfs_order(int src,stack<int>&st,vector<int>&vis,vector<vector<int>>& adj){
	    vis[src]=1;
	    for(int j=0;j<adj[src].size();j++){
	        int x=adj[src][j];
	        if(!vis[x])
	        dfs_order(x,st,vis,adj);
	    }
	    st.push(src);
	}
	void dfs(int src,vector<int>&vis,vector<vector<int>>& adj){
	    vis[src]=1;
	     for(int j=0;j<adj[src].size();j++){
	        int x=adj[src][j];
	        if(!vis[x])
	        dfs(x,vis,adj);
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>vis(V,0);
        stack<int>st;
        //step1:get order in stack
        for(int i=0;i<V;i++){
            if(!vis[i])
            dfs_order(i,st,vis,adj);
        }
        //step2:reverse the order
       vector<vector<int>> rev_adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                int x=adj[i][j];//the adjacent node to i
                rev_adj[x].push_back(i);
            }
        }
        //do dfs for the reversed nodes
         vis.assign(V, 0); // reset the visited array
        int count=0;
        while(!st.empty()){
            int src=st.top();st.pop();
            if(!vis[src]){
                count++;
                dfs(src,vis,rev_adj);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends