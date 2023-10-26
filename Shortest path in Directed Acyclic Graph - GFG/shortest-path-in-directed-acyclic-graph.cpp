//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int i,int vis[],vector<int>&topo,vector<vector<int>>& edges){
        vis[i]=1;
        for(vector<int> vec:edges){
            if(vec[0]==i&&!vis[vec[1]])dfs(vec[1],vis,topo,edges);
        }
        topo.push_back(i);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       vector<int>dist(N,INT_MAX);dist[0]=0;
       vector<int>topo;int vis[N]={0};
       for(int i=0;i<N;i++){
           if(!vis[i])dfs(i,vis,topo,edges);
       }
       //required topo order
      reverse(topo.begin(),topo.end());
       for(int i=0;i<N;i++){
           int u=topo[i];
           for (int j = 0; j < M; j++) {
               if(edges[j][0]==u){
                   int v=edges[j][1],wt=edges[j][2];
                   //not int max means that u had been visited and is a valid one
                   if(dist[u]!=INT_MAX&&(dist[u]+wt)<dist[v])
                   dist[v]=dist[u]+wt;
               }
            }
       }
       for(int i=0;i<N;i++){
           if(dist[i]==INT_MAX)dist[i]=-1;
       }
       return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends