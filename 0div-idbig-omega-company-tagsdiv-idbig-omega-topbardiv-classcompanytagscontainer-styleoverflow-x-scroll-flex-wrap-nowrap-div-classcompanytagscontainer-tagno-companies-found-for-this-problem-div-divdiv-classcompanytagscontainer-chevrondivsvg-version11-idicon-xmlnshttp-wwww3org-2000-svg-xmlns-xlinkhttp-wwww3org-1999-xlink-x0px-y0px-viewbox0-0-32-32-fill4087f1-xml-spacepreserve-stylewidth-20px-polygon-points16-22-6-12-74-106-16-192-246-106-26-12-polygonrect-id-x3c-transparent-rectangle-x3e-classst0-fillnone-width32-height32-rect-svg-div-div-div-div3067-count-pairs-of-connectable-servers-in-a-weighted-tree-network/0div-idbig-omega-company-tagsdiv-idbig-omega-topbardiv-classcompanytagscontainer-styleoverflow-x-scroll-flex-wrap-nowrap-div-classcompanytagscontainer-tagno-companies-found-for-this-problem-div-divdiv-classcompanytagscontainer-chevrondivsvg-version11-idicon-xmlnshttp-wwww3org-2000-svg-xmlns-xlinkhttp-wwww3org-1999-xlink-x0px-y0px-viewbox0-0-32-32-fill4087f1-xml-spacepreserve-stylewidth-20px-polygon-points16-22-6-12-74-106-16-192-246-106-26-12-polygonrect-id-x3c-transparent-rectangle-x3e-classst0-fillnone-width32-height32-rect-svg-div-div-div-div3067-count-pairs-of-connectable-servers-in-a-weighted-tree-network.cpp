class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>mp;
    int ss,ct;
    void dfs(int node,int parent,int d){
        if(d%ss==0)ct++;
        for(auto [ch,dis]:mp[node]){
            if(ch!=parent)
            dfs(ch,node,d+dis);
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n=edges.size()+1;ss=signalSpeed;
        for(auto vec:edges){
            int u=vec[0],v=vec[1],wt=vec[2];
            mp[u].push_back({v,wt});
            mp[v].push_back({u,wt});
        }
        vector<int>servers(n,0);
        for(int par=0;par<n;par++){
            vector<int>temp;
            int sum=0;
            for(auto[ch,d]:mp[par]){
                ct=0;
                dfs(ch,par,d);
                sum +=ct;
                temp.push_back(ct);
            }
            int ans=0;
            for(int x:temp){
                ans+=x*(sum-x);
            }
            servers[par]=ans/2;
        }
        return servers;
    }
};