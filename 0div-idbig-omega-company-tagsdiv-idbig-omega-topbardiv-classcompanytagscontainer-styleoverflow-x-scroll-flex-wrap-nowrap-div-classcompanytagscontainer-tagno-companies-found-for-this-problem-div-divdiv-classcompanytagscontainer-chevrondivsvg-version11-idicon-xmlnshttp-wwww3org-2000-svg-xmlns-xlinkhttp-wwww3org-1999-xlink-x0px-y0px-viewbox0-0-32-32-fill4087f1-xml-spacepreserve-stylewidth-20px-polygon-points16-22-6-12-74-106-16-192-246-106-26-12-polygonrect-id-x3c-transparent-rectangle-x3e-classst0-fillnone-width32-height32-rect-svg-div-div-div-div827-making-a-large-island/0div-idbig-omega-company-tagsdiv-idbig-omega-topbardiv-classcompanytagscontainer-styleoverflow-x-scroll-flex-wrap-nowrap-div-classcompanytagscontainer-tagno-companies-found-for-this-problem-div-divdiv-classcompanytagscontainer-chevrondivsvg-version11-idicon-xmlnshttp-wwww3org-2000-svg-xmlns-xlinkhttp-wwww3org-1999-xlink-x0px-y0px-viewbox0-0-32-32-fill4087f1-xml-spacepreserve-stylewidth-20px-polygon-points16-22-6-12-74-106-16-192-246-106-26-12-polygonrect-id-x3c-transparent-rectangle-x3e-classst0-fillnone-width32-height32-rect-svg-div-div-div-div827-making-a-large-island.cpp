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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        // make adjacent connections
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int node1 = i * n + j;
                    int x[] = {-1, 1, 0, 0};
                    int y[] = {0, 0, 1, -1};
                    for (int k = 0; k < 4; k++) {
                        int ix = i + x[k], jy = j + y[k];
                        if ((ix >= 0 && ix < n) && (jy >= 0 && jy < n) && grid[ix][jy]) {
                            int node2 = ix * n + jy;
                            // adjacent but not connected
                            if (ds.findParent(node1) != ds.findParent(node2))
                                ds.unionBySize(node1, node2); // make a connection
                        }
                    }
                }
            }
        }
        int max_count = 0;
        // check max size each zero can create
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    // for each adjacent one check the max size it can contribute to this zero
                    int x[] = {-1, 1, 0, 0};
                    int y[] = {0, 0, 1, -1};
                    int count = 1; // self if 0->1
        unordered_set<int>parents;//stores parent
                    for (int k = 0; k < 4; k++) {
                        int ix = i + x[k], jy = j + y[k];
                        if ((ix >= 0 && ix < n) && (jy >= 0 && jy < n) && grid[ix][jy]) {
                            int node2 = ix * n + jy;
                            parents.insert(ds.findParent(node2));
                        }
                    }
                    for(auto x:parents)
                    count+=ds.size[x];
                    max_count = max(max_count, count);
                }
            }
        }
        //as if there are no zeros
        return(max_count==0)?n*n:max_count;
    }
};
