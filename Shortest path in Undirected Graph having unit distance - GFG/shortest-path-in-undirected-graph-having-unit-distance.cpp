//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>dist(N,INT_MAX);dist[src]=0;
        queue<int>q;
        vector<int>adj[N];
        for(vector<int>vec:edges){//else we would have to traverse the complete list of vectors
            int u=vec[0],v=vec[1];
            //this is undirected so double
            adj[u].push_back(v);
            adj[v].push_back(u);
            }
        q.push(src);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:adj[u]){
                    if((dist[u]+1)<dist[v])//important:we push only those whose value updated
                    {dist[v]=dist[u]+1; q.push(v);}
            }
        }
        for(int &x:dist){
            if(x==INT_MAX)x=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends