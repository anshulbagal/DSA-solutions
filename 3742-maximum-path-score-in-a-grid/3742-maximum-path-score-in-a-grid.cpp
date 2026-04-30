class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // dp[j][c] = max score at current row, column j with cost c
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        dp[0][0] = 0; // start

        for (int i = 0; i < m; i++) {
            vector<vector<int>> new_dp(n, vector<int>(k + 1, -1));

            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                int cost = (val == 0 ? 0 : 1);

                for (int c = 0; c <= k; c++) {

                    // from top
                    if (i > 0 && dp[j][c] != -1) {
                        if (c + cost <= k) {
                            new_dp[j][c + cost] = max(
                                new_dp[j][c + cost],
                                dp[j][c] + val
                            );
                        }
                    }

                    // from left
                    if (j > 0 && new_dp[j - 1][c] != -1) {
                        if (c + cost <= k) {
                            new_dp[j][c + cost] = max(
                                new_dp[j][c + cost],
                                new_dp[j - 1][c] + val
                            );
                        }
                    }

                    // start cell case
                    if (i == 0 && j == 0 && c == 0) {
                        new_dp[j][0] = 0;
                    }
                }
            }

            dp = new_dp;
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n - 1][c]);
        }

        return ans;
    }
};