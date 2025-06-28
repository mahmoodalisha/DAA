class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1); // size set karo and initialize with -1
        return helper(n, dp);      // helper function ko call karo
    }

    int helper(int n, vector<int>& dp) {
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];

        dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
        return dp[n];
    }
};
