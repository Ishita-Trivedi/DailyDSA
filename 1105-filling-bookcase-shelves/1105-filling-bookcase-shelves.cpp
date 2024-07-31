class Solution {
public:
    int helper(int i, int currentWidth, int currentHeight, int shelfWidth, vector<vector<int>>& books, vector<vector<int>>& dp) {
        if (i >= books.size()) return currentHeight;
        if (dp[i][currentWidth] != -1) return dp[i][currentWidth];

        int thick = books[i][0], height = books[i][1];
        int sameRow = INT_MAX, nextRow;

        if (currentWidth >= thick) { // Place the book on the same row
            sameRow = helper(i + 1, currentWidth - thick, max(currentHeight, height), shelfWidth, books, dp);
        }

        // Place the book on the next row
        nextRow = currentHeight + helper(i + 1, shelfWidth - thick, height, shelfWidth, books, dp);

        return dp[i][currentWidth] = min(sameRow, nextRow);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n + 1, vector<int>(shelfWidth + 1, -1));
        return helper(0, shelfWidth, 0, shelfWidth, books, dp);
    }
};
