class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int cmax = 0;
        for (auto& x : nums) {
            sort(x.begin(), x.end(), std::greater<int>());
            cmax = max(cmax, static_cast<int>(x.size()));
        }
        int sum = 0, maxi;
        for (int j = 0; j < cmax; j++) {
            maxi = INT_MIN;
            for (int i = 0; i < nums.size(); i++) {
                if (j < nums[i].size()) {
                    maxi = max(maxi, nums[i][j]);
                }
            }
            if (maxi != INT_MIN) sum += maxi;
        }
        return sum;
    }
};
