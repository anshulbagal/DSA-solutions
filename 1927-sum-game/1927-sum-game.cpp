class Solution {
public:
    bool sumGame(string num) {
        int sumL = 0, qL = 0;
        int sumR = 0, qR = 0;

        int n = num.size();

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') {
                    qL++;
                } else {
                    sumL += num[i] - '0';
                }
            } else {
                if (num[i] == '?') {
                    qR++;
                } else {
                    sumR += num[i] - '0';
                }
            }
        }

        if ((qL + qR) % 2) {
            return true;
        }

        int ds = sumL - sumR;
        int dq = qR - qL;

        return ds != (dq / 2) * 9;
    }
};