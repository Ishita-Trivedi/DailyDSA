//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {                          // defining the constructor for initialization
        rank.resize(n + 1, 0); // secure for 1 based index too
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression->storing on return
    }
    void unionByRank(int u, int v)
    {
        // ultp is ultimate parent
        int ultp_u = findParent(u);
        int ultp_v = findParent(v);
        if (ultp_u == ultp_v)
            return; // same parent then no change to be done
        if (rank[ultp_u] < rank[ultp_v])
        {
            parent[ultp_u] = ultp_v; // smaller attached to larger no increase of rank
        }
        else if (rank[ultp_v] < rank[ultp_u])
        {
            parent[ultp_v] = ultp_u;
        }
        else
        {                            // on same rank
            parent[ultp_v] = ultp_u; // attach any
            rank[ultp_u]++;
        }
    }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
    int count=0;//adj is adjacency matrix
    for(int i=0;i<V;i++){//O(V^2)
        for(int j=0;j<V;j++){
            if(adj[i][j]==1)
            { // means node between i->j
            ds.unionByRank(i,j);//make a component connection
            }
        }
    }
    //now just count the ultimate parents
    for(int i=0;i<V;i++){//O(V)
        if(ds.findParent(i)==i)count++;//can use ds.parent[i]==i if parent array is public
    }
    return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends