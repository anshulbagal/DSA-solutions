class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // Step 1: Basic validation
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != lcp[j][i]) return "";
            }
        }

        // Step 2: DSU setup
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) parent[a] = b;
        };

        // Step 3: Merge indices with lcp > 0
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }

        // Step 4: Assign characters
        vector<char> groupChar(n, 0);
        char ch = 'a';

        for (int i = 0; i < n; i++) {
            int p = find(i);
            if (groupChar[p] == 0) {
                if (ch > 'z') return ""; // too many groups
                groupChar[p] = ch++;
            }
        }

        string word(n, '?');
        for (int i = 0; i < n; i++) {
            word[i] = groupChar[find(i)];
        }

        // Step 5: Validate LCP again
        vector<vector<int>> check(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    if (i == n - 1 || j == n - 1)
                        check[i][j] = 1;
                    else
                        check[i][j] = 1 + check[i + 1][j + 1];
                } else {
                    check[i][j] = 0;
                }

                if (check[i][j] != lcp[i][j]) return "";
            }
        }

        return word;
    }
};