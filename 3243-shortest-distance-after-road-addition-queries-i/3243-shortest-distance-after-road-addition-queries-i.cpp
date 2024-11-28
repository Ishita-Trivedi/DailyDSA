class Solution {
public:
     int mindistance(int n,  vector<vector<pair<int, int>>> &adj){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //dist,start
        vector<int>distTo(n,INT_MAX);
        distTo[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int d=pq.top().first,u=pq.top().second;
            if(u==n-1)return d;
            pq.pop();
            for(auto p:adj[u]){
                int v=p.first,w=p.second;
                if((d+1)<distTo[v]){
                    distTo[v]=d+1;
                    pq.push({distTo[v],v});
                }
            }
        }
        return distTo[n-1];
     }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<n-1;i++)
        adj[i].push_back({i+1,1});
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0],v=queries[i][1];
            adj[u].push_back({v,1});
            int d=mindistance(n,adj);
            // cout<<d<<" ";
            ans.push_back(d);
        }
        return ans;
    }
};