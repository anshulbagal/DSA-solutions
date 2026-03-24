class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int N = n * m;
        const int MOD = 12345;

        vector<int> arr;
        for (auto &row : grid) {
            for (int x : row) {
                arr.push_back(x % MOD);
            }
        }

        vector<int> prefix(N, 1), suffix(N, 1);

        // prefix
        for (int i = 1; i < N; i++) {
            prefix[i] = (prefix[i-1] * arr[i-1]) % MOD;
        }

        // suffix
        for (int i = N - 2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * arr[i+1]) % MOD;
        }

        // result in 2D
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < N; i++) {
            int val = (prefix[i] * suffix[i]) % MOD;
            res[i / m][i % m] = val;
        }

        return res;
    }
};