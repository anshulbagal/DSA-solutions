class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // store indices and digits of non-zero elements
        vector<int> idx;
        vector<int> digit;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                idx.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // prefix sum of digits
        vector<long long> prefSum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        // prefix number
        vector<long long> prefNum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
        }

        // powers of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            // find first index >= l
            int left = lower_bound(idx.begin(), idx.end(), l) - idx.begin();

            // find last index <= r
            int right = upper_bound(idx.begin(), idx.end(), r) - idx.begin() - 1;

            if (left > right) {
                ans.push_back(0);
                continue;
            }

            int len = right - left + 1;

            // get number x
            long long x = prefNum[right + 1];
            long long sub = (prefNum[left] * pow10[len]) % MOD;

            x = (x - sub + MOD) % MOD;

            // get sum
            long long sum = prefSum[right + 1] - prefSum[left];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};