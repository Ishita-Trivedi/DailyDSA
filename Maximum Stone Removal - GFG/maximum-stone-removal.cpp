//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet {
public:
vector<int> rank, parent, size;
    DisjointSet(int n) { // defining the constructor for initialization
        // rank.resize(n + 1, 0); // secure for 1 based index too
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // path compression->storing on return
    }

    void unionBySize(int u, int v) {
        // ultp is ultimate parent
        int ultp_u = findParent(u);
        int ultp_v = findParent(v);
        if (ultp_u == ultp_v)
            return; // same component elements->already connected
        if (size[ultp_u] < size[ultp_v]) {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u]; // as v larger
        } else { // in equal case any will work
            parent[ultp_v] = ultp_u; // u larger
            size[ultp_u] += size[ultp_v];
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
       //n is the number of stones
       int maxRow=0,maxCol=0;
       for(auto vec:stones){
           maxRow=max(maxRow,vec[0]);
           maxCol=max(maxCol,vec[1]);
       }
       DisjointSet ds(maxRow+maxCol+1);//total nodes for ds
       //connect each row and col for every stone
       //also store the node1 and node2 having the stone
       unordered_map<int,int>nodes;
       for(auto vec:stones){
           int node1=vec[0],node2=vec[1]+maxRow+1;
           ds.unionBySize(node1,node2);
           nodes[node1]=1;nodes[node2]=1;
       }
       //count the boss parents in the nodes indexes,as indexes not having stones absent in nodes
       int components=0;
       for(auto x:nodes){
           if(ds.findParent(x.first)==x.first)components++;
       }
       return n-components;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends