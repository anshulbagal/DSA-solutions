class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        
        vector dp(m, vector(n, vector<int>(3, INT_MIN)));
        
        // base case
        for(int k = 0; k < 3; k++){
            dp[0][0][k] = coins[0][0];
            if(coins[0][0] < 0 && k > 0)
                dp[0][0][k] = 0; // neutralize
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;

                for(int k = 0; k < 3; k++){
                    int best = INT_MIN;

                    // from top
                    if(i > 0){
                        // don't neutralize
                        best = max(best, dp[i-1][j][k] + coins[i][j]);

                        // neutralize
                        if(coins[i][j] < 0 && k > 0)
                            best = max(best, dp[i-1][j][k-1]);
                    }

                    // from left
                    if(j > 0){
                        // don't neutralize
                        best = max(best, dp[i][j-1][k] + coins[i][j]);

                        // neutralize
                        if(coins[i][j] < 0 && k > 0)
                            best = max(best, dp[i][j-1][k-1]);
                    }

                    dp[i][j][k] = best;
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};