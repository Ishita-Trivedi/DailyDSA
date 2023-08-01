class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& copy, vector<vector<int>>& ans, int k) {
        if (copy.size() == k) {
            ans.push_back(copy);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            copy.push_back(nums[j]);
            helper(j + 1, nums, copy, ans, k);
            copy.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> a;
        vector<int> store;
        for (int i = 1; i <= n; i++)
            a.push_back(i);
        vector<vector<int>> ans;
        helper(0, a, store, ans, k);
        return ans;
    }
};
