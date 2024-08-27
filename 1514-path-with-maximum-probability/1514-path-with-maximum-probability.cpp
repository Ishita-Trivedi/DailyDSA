class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> dist(n, 0.0);
        vector<vector<pair<int, double>>> adj(n);
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double wt = succProb[i];
            adj[u].emplace_back(v, wt);
            adj[v].emplace_back(u, wt);
        }
        
        priority_queue<pair<double, int>> pq;
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});
        
        while (!pq.empty()) {
            auto [val, u] = pq.top(); pq.pop();
            if (u == end_node) return val;
            
            for (auto& [v, wt] : adj[u]) {
                if (dist[v] < val * wt) {
                    dist[v] = val * wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return 0.0;
    }
};
