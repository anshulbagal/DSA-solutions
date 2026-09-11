class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;

        for (int num = 100; num <= 998; num += 2) {
            vector<int> cnt(10, 0);

            for (int d : digits)
                cnt[d]++;

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            if (cnt[a] > 0) {
                cnt[a]--;

                if (cnt[b] > 0) {
                    cnt[b]--;

                    if (cnt[c] > 0)
                        ans++;
                }
            }
        }

        return ans;
    }
};