class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        
        for (auto &row : grid) {
            for (int num : row) {
                v.push_back(num);
            }
        }

        int rem = v[0] % x;
        for (int num : v) {
            if (num % x != rem) return -1;
        }

        sort(v.begin(), v.end());
        int mid = v[v.size() / 2];

        int ans = 0;
        for (int num : v) {
            ans += abs(num - mid) / x;
        }

        return ans;
    }
};