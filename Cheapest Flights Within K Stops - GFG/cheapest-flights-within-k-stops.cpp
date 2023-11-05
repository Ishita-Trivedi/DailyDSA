//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto vec : flights) {
            int u = vec[0], v = vec[1], wt = vec[2];
            adj[u].push_back({v, wt});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;  // Initialize the distance to the source node.
        queue<vector<int>> q;
        q.push({0, src, 0});  // stops, node, price

        while (!q.empty()) {
            auto vec = q.front();
            q.pop();
            int stops = vec[0], u = vec[1], price = vec[2];

            if (stops > k) continue;  // Skip if the number of stops exceeds k.

            for (auto p : adj[u]) {
                int v = p.first, wt = p.second;
                if (dist[v] > wt + price) {
                    dist[v] = wt + price;
                    q.push({stops + 1, v, wt + price});
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends