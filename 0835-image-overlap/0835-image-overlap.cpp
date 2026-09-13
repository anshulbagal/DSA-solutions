class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        // Try every possible vertical shift
        for (int dr = -(n - 1); dr <= n - 1; dr++) {

            // Try every possible horizontal shift
            for (int dc = -(n - 1); dc <= n - 1; dc++) {

                int count = 0;

                // Check every 1 in img1
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {

                        if (img1[i][j] == 1) {

                            int ni = i + dr;
                            int nj = j + dc;

                            // Is the shifted position inside the matrix?
                            if (ni >= 0 && ni < n &&
                                nj >= 0 && nj < n) {

                                // Does img2 also have 1 here?
                                if (img2[ni][nj] == 1) {
                                    count++;
                                }
                            }
                        }
                    }
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};