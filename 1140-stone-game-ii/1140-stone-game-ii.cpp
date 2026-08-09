class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        // All piles are already taken
        if (i >= n)
            return 0;

        // Already calculated
        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        // Current player can take X piles
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            // Stones taken by current player
            int taken = prefix[i + X] - prefix[i];

            // Remaining stones after taking X piles
            int remaining = prefix[n] - prefix[i + X];

            // Opponent's best possible score
            int opponent = solve(i + X, max(M, X));

            // Current player's total
            int current = taken + remaining - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // Prefix sum
        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + piles[i];
        }

        // M can go up to n
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};