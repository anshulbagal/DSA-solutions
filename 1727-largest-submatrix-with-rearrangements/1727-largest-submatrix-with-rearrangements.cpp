class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            // Step 1: build heights
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    height[j] += 1;
                else
                    height[j] = 0;
            }

            // Step 2: sort heights in descending order
            vector<int> sorted = height;
            sort(sorted.begin(), sorted.end(), greater<int>());

            // Step 3: compute max area
            for (int j = 0; j < n; j++) {
                ans = max(ans, sorted[j] * (j + 1));
            }
        }

        return ans;
    }
};