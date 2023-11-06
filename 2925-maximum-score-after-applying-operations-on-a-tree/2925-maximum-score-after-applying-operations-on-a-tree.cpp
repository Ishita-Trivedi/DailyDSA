class Solution {
private:
    long long dfs(int start,vector<int>adj[],vector<int>& values,vector<int>& vis){
        if(adj[start].size()==1&&start!=0)
        return (long long)values[start];
        vis[start]=1;
        long long childsum=0;
        for(int x:adj[start]){
            if(!vis[x])
            childsum +=dfs(x,adj,values,vis);
        }
       return min(static_cast<long long>(childsum), static_cast<long long>(values[start]));

    }
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        //undirected
        int n=values.size();
        vector<int>adj[n];
        for(auto vec:edges){
            int u=vec[0],v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        long long sum=0;
        for(auto x:values)
            sum+=x;
        return sum-dfs(0,adj,values,vis);
    }
};