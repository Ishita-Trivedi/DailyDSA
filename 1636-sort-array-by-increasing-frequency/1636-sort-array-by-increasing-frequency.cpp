class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> vec;
        map<int, int> mp;
        
        // Count the frequency of each number
        for (int x : nums)
            mp[x]++;
        
        // Create a vector of pairs {frequency, number}
        for (auto x : mp)
            vec.push_back({x.second, x.first});
        
        // Sort the vector with the custom comparator
        sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        
        // Build the result based on the sorted frequencies
        vector<int> ans;
        for (auto p : vec)
            for (int i = 0; i < p.first; ++i)
                ans.push_back(p.second);
        
        return ans;
    }
};
