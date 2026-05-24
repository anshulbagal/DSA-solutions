class Solution {
public:
    int memo[1001];
    
    int dp(vector<int>& arr, int i, int d) {
        if (memo[i] != -1) return memo[i];
        
        int best = 1; // at minimum, just stand here
        int n = arr.size();
        
        // Jump right
        for (int x = 1; x <= d && i + x < n; x++) {
            if (arr[i + x] >= arr[i]) break; // blocked
            best = max(best, 1 + dp(arr, i + x, d));
        }
        
        // Jump left
        for (int x = 1; x <= d && i - x >= 0; x++) {
            if (arr[i - x] >= arr[i]) break; // blocked
            best = max(best, 1 + dp(arr, i - x, d));
        }
        
        return memo[i] = best;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        memset(memo, -1, sizeof(memo));
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
            ans = max(ans, dp(arr, i, d));
        return ans;
    }
};