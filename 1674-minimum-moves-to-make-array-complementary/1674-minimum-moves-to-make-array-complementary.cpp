class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        int pairs = n / 2;

        // baseline = every pair needs 2 moves
        int current = 2 * pairs;

        for (int i = 0; i < pairs; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;

            // make cost 1 in [low, high]
            diff[low] -= 1;
            diff[high + 1] += 1;

            // make cost 0 at a+b
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
        }

        int ans = INT_MAX;

        int extra = 0;

        for (int s = 2; s <= 2 * limit; s++) {

            extra += diff[s];

            ans = min(ans, current + extra);
        }

        return ans;
    }
};