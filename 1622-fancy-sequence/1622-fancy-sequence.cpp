class Fancy {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> arr;
    long long a = 1, b = 0;

    long long modPow(long long x, long long y) {
        long long res = 1;
        x %= MOD;
        while (y) {
            if (y & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }

    long long modInv(long long x) {
        return modPow(x, MOD - 2);
    }

    Fancy() {}

    void append(int val) {
        long long stored = ((val - b) % MOD + MOD) % MOD;
        stored = (stored * modInv(a)) % MOD;
        arr.push_back(stored);
    }

    void addAll(int inc) {
        b = (b + inc) % MOD;
    }

    void multAll(int m) {
        a = (a * m) % MOD;
        b = (b * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * a % MOD + b) % MOD;
    }
};