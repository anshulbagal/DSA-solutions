class Solution {
public:
    int countOneBits(int num) {
        int count = 0;

        while (num > 0) {
            if (num % 2 == 1)
                count++;

            num /= 2;
        }

        return count;
    }

    vector<int> countBits(int n) {

        vector<int> ans;

        for (int i = 0; i <= n; i++) {
            ans.push_back(countOneBits(i));
        }

        return ans;
    }
};