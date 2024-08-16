class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        if (arrays.empty()) return 0;

        int maximum = 0;
        int minVal = arrays[0][0];
        int maxVal = arrays[0][arrays[0].size()-1];

        for (int i = 1; i < arrays.size(); ++i) {
            int currMin =  arrays[i][0];
            int currMax = arrays[i][arrays[i].size()-1];

            maximum = max(maximum, abs(currMax - minVal));
            maximum = max(maximum, abs(maxVal - currMin));

            minVal = min(minVal, currMin);
            maxVal = max(maxVal, currMax);
        }

        return maximum;
    }
};