class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countWays(long long x, vector<int>& coins) {
        int n = coins.size();
        long long cnt = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    L = lcm(L, coins[i]);

                    if (L > x) break;
                }
            }

            if (L > x) continue;

            if (bits % 2)
                cnt += x / L;
            else
                cnt -= x / L;
        }

        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (countWays(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};