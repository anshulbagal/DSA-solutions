class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int num = x;
        while(num != 0){
            int digit = num % 10;
                        // Check for positive overflow
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7))
                return 0;

            // Check for negative overflow
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8))
                return 0;
            ans = ans * 10 +digit;
            num = num/10;
        }
        return ans;
    }
};