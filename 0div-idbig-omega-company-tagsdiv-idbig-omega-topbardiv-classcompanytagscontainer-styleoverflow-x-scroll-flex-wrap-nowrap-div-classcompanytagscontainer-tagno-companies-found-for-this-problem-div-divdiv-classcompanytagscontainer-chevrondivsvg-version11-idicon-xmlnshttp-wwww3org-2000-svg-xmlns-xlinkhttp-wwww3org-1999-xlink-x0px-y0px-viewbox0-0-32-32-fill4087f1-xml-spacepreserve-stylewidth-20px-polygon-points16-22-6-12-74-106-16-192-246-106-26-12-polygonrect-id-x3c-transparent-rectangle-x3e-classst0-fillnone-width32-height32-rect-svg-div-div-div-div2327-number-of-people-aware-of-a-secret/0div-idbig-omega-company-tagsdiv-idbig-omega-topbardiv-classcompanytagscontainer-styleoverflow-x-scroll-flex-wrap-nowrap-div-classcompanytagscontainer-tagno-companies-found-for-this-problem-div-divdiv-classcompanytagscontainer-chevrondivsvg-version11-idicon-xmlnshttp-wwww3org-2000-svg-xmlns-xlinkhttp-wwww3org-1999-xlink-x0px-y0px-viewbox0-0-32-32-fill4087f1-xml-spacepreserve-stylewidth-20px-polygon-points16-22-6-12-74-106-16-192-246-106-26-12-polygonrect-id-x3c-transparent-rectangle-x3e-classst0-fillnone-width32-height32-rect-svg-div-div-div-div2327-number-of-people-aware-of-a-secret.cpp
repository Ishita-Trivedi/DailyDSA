class Solution {
    typedef long long ll;

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> dp(n + 1, 0);
        ll ans = 0, mod = 1e9 + 7, currknowing = 0; // to indicate a&other previously
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            ll newpeoplesharing = dp[max(0, i - delay)];
            ll forgettingtoday = dp[max(0, i - forget)];
            currknowing += (newpeoplesharing - forgettingtoday + mod) % mod;
            dp[i] = currknowing;
        }
        for (int i = n - forget + 1; i <= n; i++) {
            ans = (ans + dp[i]) % mod;
        }
        return ans % mod;
    }
};
