class Solution {
public:
    int bsearch(vector<pair<int,int>>& st, int value) {
        //Heights are sorted in descending order as we iterate backward over the buildings
        int l = 0, r = st.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (st[mid].first > value) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = heights.size();
        vector<vector<pair<int, int>>> store(n); // Corrected type
        vector<pair<int, int>> st;

        for (int i = 0; i < queries.size(); i++) {
            int ai = queries[i][0], bi = queries[i][1];
            // Remove inconsistencies
            if (ai > bi) // Ensure ai <= bi
                swap(ai, bi);
            if (heights[bi] > heights[ai] || ai == bi)
                ans.push_back(bi);
            else {
                ans.push_back(-1);
                store[bi].push_back({heights[ai], i}); // Now works as expected
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < store[i].size(); j++) {
                int greaterVal = store[i][j].first, queryNo = store[i][j].second;
                int pos = bsearch(st, greaterVal);
                if (pos != -1)
                    ans[queryNo] = st[pos].second;
            }
            while (!st.empty() && st.back().first <= heights[i])
                st.pop_back();
            st.push_back({heights[i], i});
        }

        return ans;
    }
};
