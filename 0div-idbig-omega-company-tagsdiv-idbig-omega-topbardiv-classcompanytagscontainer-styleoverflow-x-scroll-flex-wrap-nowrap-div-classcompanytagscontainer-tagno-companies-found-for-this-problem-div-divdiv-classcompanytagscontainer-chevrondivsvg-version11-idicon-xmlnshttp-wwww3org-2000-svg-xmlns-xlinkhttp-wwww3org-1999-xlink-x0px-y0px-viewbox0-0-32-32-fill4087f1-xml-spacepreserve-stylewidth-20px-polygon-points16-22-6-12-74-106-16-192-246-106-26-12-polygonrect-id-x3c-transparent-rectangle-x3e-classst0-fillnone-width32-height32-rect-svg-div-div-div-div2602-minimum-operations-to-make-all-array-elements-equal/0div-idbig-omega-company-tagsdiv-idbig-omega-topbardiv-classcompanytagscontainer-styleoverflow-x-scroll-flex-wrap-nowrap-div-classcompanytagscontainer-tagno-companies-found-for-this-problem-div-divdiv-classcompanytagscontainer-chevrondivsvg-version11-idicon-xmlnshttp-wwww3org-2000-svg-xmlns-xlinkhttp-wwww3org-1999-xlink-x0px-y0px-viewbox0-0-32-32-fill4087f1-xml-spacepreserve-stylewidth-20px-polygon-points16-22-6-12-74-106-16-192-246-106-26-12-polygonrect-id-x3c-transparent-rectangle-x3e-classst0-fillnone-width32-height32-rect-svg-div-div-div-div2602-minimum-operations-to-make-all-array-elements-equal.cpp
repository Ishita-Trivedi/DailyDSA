class Solution {
public:
   vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<long long> ans, prefix(n);
    prefix[0]=nums[0];
    for (int i = 1; i < n; i++)
        prefix[i ] = prefix[i-1] + (long long) nums[i];
    for (int& x : queries) {
        int i = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        long long lhs=1LL*x*i-((i>0)?prefix[i-1]:0);
        long long rhs=(prefix[n-1]-((i>0)?prefix[i-1]:0)-1LL*x*(n-i));
        ans.push_back(lhs+rhs);
        // ans.push_back(1LL * x * (2 * i - n) + prefix[n] - 2 * prefix[i]);
    }
    return ans;
}
};