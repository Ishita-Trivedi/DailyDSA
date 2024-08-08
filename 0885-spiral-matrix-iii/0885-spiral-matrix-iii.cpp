class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    vector<vector<int>> spiralMatrixIII(int n, int m, int rs, int cs) {
        vector<vector<int>> ans;
        int total = n * m;
        ans.push_back({rs, cs});
        if (total == 1) return ans;

        int steps = 1; // Initial steps to move in one direction
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
        int dirIndex = 0; // Start with moving right

        while (ans.size() < total) {
            for (int i = 0; i < 2; ++i) { // Two times for each step size
                for (int j = 0; j < steps; ++j) {
                    rs += directions[dirIndex][0];
                    cs += directions[dirIndex][1];
                    if (isValid(rs, cs, n, m)) {
                        ans.push_back({rs, cs});
                        if (ans.size() == total) return ans;
                    }
                }
                dirIndex = (dirIndex + 1) % 4; // Change direction
            }
            steps++; // Increase the steps after two directions
        }

        return ans;
    }
};
