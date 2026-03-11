class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;

        string s = "";

        int temp = n;

        // convert to binary
        while(temp > 0) {
            s = char((temp % 2) + '0') + s;
            temp /= 2;
        }

        // flip bits
        for(char &c : s) {
            c = (c == '1') ? '0' : '1';
        }

        // convert binary -> decimal
        int ans = 0;
        for(char c : s) {
            ans = ans * 2 + (c - '0');
        }

        return ans;
    }
};