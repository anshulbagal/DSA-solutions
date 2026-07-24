class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> vals(st.begin(), st.end());

        vector<bool> pairXor(2048, false);
        vector<bool> ans(2048, false);

        // All XORs of two values
        for (int a : vals) {
            for (int b : vals) {
                pairXor[a ^ b] = true;
            }
        }

        // Add the third value
        for (int x = 0; x < 2048; x++) {
            if (!pairXor[x]) continue;

            for (int c : vals) {
                ans[x ^ c] = true;
            }
        }

        int cnt = 0;
        for (bool x : ans)
            if (x) cnt++;

        return cnt;
    }
};