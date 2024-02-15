class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Construct adjacency list and calculate in-degrees
        for (const auto& prerequisite : prerequisites) {
            int u = prerequisite[0], v = prerequisite[1];
            adj[u].push_back(v);
            ++inDegree[v];
        }

        // Perform topological sort using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++count;
            for (int v : adj[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return count == numCourses;
    }
};
